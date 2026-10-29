import unittest
from contextlib import contextmanager
from unittest.mock import patch

from opendbc.car.can_definitions import CanData
from opendbc.car.car_helpers import can_fingerprint, fingerprint
from opendbc.car.gm.values import CAR
from opendbc.car.vin_identity import identify_by_vin

RECORDED_TRAX_POWERTRAIN = {
  0xBE: 6, 0xC1: 8, 0xC5: 8, 0xC9: 8, 0xD1: 7, 0xD3: 2, 0xF1: 6, 0xF9: 8, 0x120: 5, 0x12A: 8, 0x130: 3, 0x135: 8,
  0x137: 8, 0x139: 8, 0x140: 4, 0x142: 7, 0x148: 1, 0x160: 5, 0x17D: 8, 0x180: 4, 0x182: 8, 0x184: 8, 0x19D: 8,
  0x1C3: 8, 0x1C4: 8, 0x1C5: 6, 0x1C7: 7, 0x1DF: 3, 0x1E1: 7, 0x1E5: 8, 0x1E9: 8, 0x1F1: 8, 0x1F4: 6, 0x1F5: 8,
  0x214: 6, 0x230: 8, 0x232: 8, 0x233: 5, 0x235: 5, 0x260: 8, 0x261: 6, 0x262: 6, 0x263: 6, 0x264: 8, 0x265: 8,
  0x2C3: 8, 0x2CB: 8, 0x2CD: 5, 0x2F9: 7, 0x315: 5, 0x320: 6, 0x32A: 8, 0x348: 5, 0x34A: 5, 0x34C: 8, 0x365: 4,
  0x370: 6, 0x3D1: 8, 0x3E9: 8, 0x3F3: 6, 0x3F9: 8, 0x3FC: 8, 0x4C1: 8, 0x4C5: 5, 0x4D1: 8, 0x4E1: 8, 0x4EB: 8,
  0x4ED: 7, 0x4EF: 4, 0x4F1: 8, 0x4F3: 1, 0x4F7: 8, 0x500: 4, 0x510: 4, 0x514: 8, 0x78A: 7,
}
RECORDED_TRAX_LAYOUT = {0: RECORDED_TRAX_POWERTRAIN}
TRAX_VINS = {"R": "KL77LHEP0RC000000", "S": "KL77LHEP0SC000000", "T": "KL77LHEP0TC000000"}
PRE_REDESIGN_TRAX_VIN = "KL7CJPSB0PB000000"
COLLIDING_PLATFORM_VINS = ("1GCUYDED0LZ000000", "3GNAXKEV0LS000000")


def recorded_frames():
  return [CanData(address, bytes(length), 0) for address, length in RECORDED_TRAX_POWERTRAIN.items()]


@contextmanager
def discovery_without_firmware(vin):
  with patch('opendbc.car.car_helpers.normal_bus_query_brand', return_value=None), \
       patch('opendbc.car.car_helpers.get_vin', return_value=(0x7E8, 0, vin)), \
       patch('opendbc.car.car_helpers.get_present_ecus', return_value=set()), \
       patch('opendbc.car.car_helpers.get_fw_versions_ordered', return_value=[]), \
       patch('opendbc.car.car_helpers.match_fw_to_car', return_value=(True, set())), \
       patch('opendbc.car.car_helpers.can_fingerprint', return_value=(None, RECORDED_TRAX_LAYOUT)):
    yield


class TestTraxVinIdentity(unittest.TestCase):
  def identify(self, vin):
    return identify_by_vin(vin, fw_candidates=set(), can_layout=RECORDED_TRAX_LAYOUT)

  def test_recorded_trax_traffic_is_ambiguous_by_can_alone(self):
    frames = iter([recorded_frames()])
    candidate, _ = can_fingerprint(lambda **_: [next(frames, [])])
    self.assertIsNone(candidate)

  def test_trax_vins_identify_the_trax_for_every_supported_model_year(self):
    for year_code, vin in TRAX_VINS.items():
      with self.subTest(year_code=year_code):
        self.assertEqual(self.identify(vin), CAR.CHEVROLET_TRAX)

  def test_pre_redesign_trax_vin_identifies_nothing(self):
    self.assertIsNone(self.identify(PRE_REDESIGN_TRAX_VIN))

  def test_vins_of_platforms_sharing_the_trax_layout_identify_nothing(self):
    for vin in COLLIDING_PLATFORM_VINS:
      with self.subTest(vin=vin):
        self.assertIsNone(self.identify(vin))

  def test_fingerprint_reports_a_vin_identity_as_inexact(self):
    with discovery_without_firmware(TRAX_VINS["S"]):
      candidate, _, vin, _, _, exact_match = fingerprint(lambda **_: [], lambda _: None, lambda _: None, None)
    self.assertEqual((candidate, vin, exact_match), (CAR.CHEVROLET_TRAX, TRAX_VINS["S"], False))

  def test_fingerprint_keeps_an_explicit_choice_over_the_vin(self):
    with patch.dict('os.environ', {'FINGERPRINT': str(CAR.CHEVROLET_EQUINOX)}), discovery_without_firmware(TRAX_VINS["S"]):
      candidate, *_ = fingerprint(lambda **_: [], lambda _: None, lambda _: None, None)
    self.assertEqual(candidate, CAR.CHEVROLET_EQUINOX)


if __name__ == "__main__":
  unittest.main()
