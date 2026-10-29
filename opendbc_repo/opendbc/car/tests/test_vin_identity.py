import sys
import types
import unittest
from contextlib import contextmanager
from unittest.mock import patch

from opendbc.car.car_helpers import fingerprint
from opendbc.car.fingerprints import _FINGERPRINTS as FINGERPRINTS
from opendbc.car.values import PLATFORMS
from opendbc.car.vin import Vin
from opendbc.car.vin_identity import MODEL_YEAR_CODES, VinPattern, identify_by_vin, model_year_codes, registered_patterns

ALPHA = VinPattern(wmis=frozenset({"AAA"}), descriptor="1B", model_year_codes=model_year_codes(2024, 2025))
BETA = VinPattern(wmis=frozenset({"BBB"}), descriptor="2C", model_year_codes=model_year_codes(2024, 2025))
ALPHA_VIN = "AAA1BXXXXRX000000"
PATTERNS = {"ALPHA": (ALPHA,), "BETA": (BETA,)}
NO_CAN: dict[int, dict[int, int]] = {}

TABLE_PLATFORM = "CHEVROLET_SILVERADO"
TABLE_PATTERNS = {TABLE_PLATFORM: (ALPHA,)}
TABLE_LAYOUT = {0: dict(FINGERPRINTS[TABLE_PLATFORM][0])}
UNKNOWN_ADDRESS = 0x5FF


class TestModelYearCodes(unittest.TestCase):
  def test_codes_follow_the_vin_model_year_cycle(self):
    expected = {2010: "A", 2017: "H", 2018: "J", 2024: "R", 2025: "S", 2026: "T", 2031: "1", 2039: "9"}
    for year, code in expected.items():
      with self.subTest(year=year):
        self.assertEqual(model_year_codes(year, year), {code})

  def test_codes_never_use_letters_reserved_by_the_vin_standard(self):
    self.assertFalse(set("IOQUZ") & model_year_codes(2010, 2039))
    self.assertEqual(len(model_year_codes(2010, 2039)), len(MODEL_YEAR_CODES))


class TestVinPattern(unittest.TestCase):
  def test_matches_wmi_descriptor_and_model_year(self):
    self.assertTrue(ALPHA.matches(Vin(ALPHA_VIN)))

  def test_rejects_any_mismatched_section(self):
    for vin in ("ZZZ1BXXXXRX000000", "AAA9BXXXXRX000000", "AAA1BXXXXPX000000"):
      with self.subTest(vin=vin):
        self.assertFalse(ALPHA.matches(Vin(vin)))


class TestIdentifyByVin(unittest.TestCase):
  def identify(self, vin, fw_candidates=frozenset(), can_layout=NO_CAN, patterns=PATTERNS):
    return identify_by_vin(vin, fw_candidates=fw_candidates, can_layout=can_layout, patterns=patterns)

  def test_unique_match_without_firmware_identifies_the_platform(self):
    self.assertEqual(self.identify(ALPHA_VIN), "ALPHA")

  def test_invalid_or_unknown_vin_identifies_nothing(self):
    for vin in ("", "ALPHA", "QQQ1BXXXXRX000000", "0" * 17, "CCC1BXXXXRX000000"):
      with self.subTest(vin=vin):
        self.assertIsNone(self.identify(vin))

  def test_vin_matching_several_platforms_identifies_nothing(self):
    self.assertIsNone(self.identify(ALPHA_VIN, patterns={"ALPHA": (ALPHA,), "ALPHA_TWIN": (ALPHA,)}))

  def test_firmware_candidates_are_narrowed_by_the_vin(self):
    self.assertEqual(self.identify(ALPHA_VIN, fw_candidates={"ALPHA", "BETA"}), "ALPHA")

  def test_firmware_candidates_are_never_extended_by_the_vin(self):
    self.assertIsNone(self.identify(ALPHA_VIN, fw_candidates={"BETA", "GAMMA"}))

  def test_platform_with_a_table_is_identified_when_recorded_can_fits(self):
    self.assertEqual(self.identify(ALPHA_VIN, can_layout=TABLE_LAYOUT, patterns=TABLE_PATTERNS), TABLE_PLATFORM)

  def test_platform_with_a_table_is_rejected_when_recorded_can_contradicts_it(self):
    contradicting = {0: {**TABLE_LAYOUT[0], UNKNOWN_ADDRESS: 8}}
    self.assertIsNone(self.identify(ALPHA_VIN, can_layout=contradicting, patterns=TABLE_PATTERNS))

  def test_platform_with_a_table_needs_recorded_can(self):
    self.assertIsNone(self.identify(ALPHA_VIN, patterns=TABLE_PATTERNS))

  def test_diagnostic_responses_never_contradict_a_table(self):
    with_diagnostics = {0: {**TABLE_LAYOUT[0], 0x7DF: 8, 0x7E0: 8, 0x7E8: 8}}
    self.assertEqual(self.identify(ALPHA_VIN, can_layout=with_diagnostics, patterns=TABLE_PATTERNS), TABLE_PLATFORM)


@contextmanager
def discovery_without_firmware(vin):
  with patch('opendbc.car.vin_identity.registered_patterns', return_value=PATTERNS), \
       patch('opendbc.car.car_helpers.normal_bus_query_brand', return_value=None), \
       patch('opendbc.car.car_helpers.get_vin', return_value=(0x7E8, 0, vin)), \
       patch('opendbc.car.car_helpers.get_present_ecus', return_value=set()), \
       patch('opendbc.car.car_helpers.get_fw_versions_ordered', return_value=[]), \
       patch('opendbc.car.car_helpers.match_fw_to_car', return_value=(True, set())), \
       patch('opendbc.car.car_helpers.can_fingerprint', return_value=(None, NO_CAN)):
    yield


class TestFingerprintVinFallback(unittest.TestCase):
  def test_vin_identity_is_reported_as_inexact(self):
    with discovery_without_firmware(ALPHA_VIN):
      candidate, _, vin, _, _, exact_match = fingerprint(lambda **_: [], lambda _: None, lambda _: None, None)
    self.assertEqual((candidate, vin, exact_match), ("ALPHA", ALPHA_VIN, False))

  def test_explicit_fingerprint_overrides_the_vin(self):
    with patch.dict('os.environ', {'FINGERPRINT': "BETA"}), discovery_without_firmware(ALPHA_VIN):
      candidate, *_ = fingerprint(lambda **_: [], lambda _: None, lambda _: None, None)
    self.assertEqual(candidate, "BETA")


class TestRegisteredPatterns(unittest.TestCase):
  def setUp(self):
    registered_patterns.cache_clear()
    self.addCleanup(registered_patterns.cache_clear)

  def test_patterns_are_collected_from_brand_vin_pattern_modules(self):
    brand_module = types.ModuleType("opendbc.car.gm.vin_patterns")
    brand_module.VIN_PATTERNS = {"CHEVROLET_TRAX": (ALPHA,)}
    with patch.dict(sys.modules, {brand_module.__name__: brand_module}):
      self.assertEqual(registered_patterns(), {"CHEVROLET_TRAX": (ALPHA,)})

  def test_every_pattern_targets_a_known_platform_with_well_formed_sections(self):
    for platform, patterns in registered_patterns().items():
      with self.subTest(platform=platform):
        self.assertIn(platform, PLATFORMS)
        for pattern in patterns:
          self.assertTrue(pattern.wmis)
          self.assertTrue(all(len(wmi) == 3 for wmi in pattern.wmis))
          self.assertTrue(0 < len(pattern.descriptor) <= 6)
          self.assertTrue(pattern.model_year_codes)
          self.assertLessEqual(pattern.model_year_codes, set(MODEL_YEAR_CODES))


if __name__ == "__main__":
  unittest.main()
