from collections.abc import Collection, Mapping
from dataclasses import dataclass
from functools import cache

from opendbc.car.can_definitions import CanData
from opendbc.car.fingerprints import all_legacy_fingerprint_cars, eliminate_incompatible_cars
from opendbc.car.interfaces import get_interface_attr
from opendbc.car.vin import Vin, is_valid_vin

MODEL_YEAR_CODES = "ABCDEFGHJKLMNPRSTVWXY123456789"
MODEL_YEAR_CYCLE_START = 2010
FINGERPRINT_BUSES = (0, 1)
DIAGNOSTIC_ADDRESSES = frozenset((0x7DF, 0x7E0, 0x7E8))

CanLayout = Mapping[int, Mapping[int, int]]


def model_year_codes(first_year: int, last_year: int) -> frozenset[str]:
  return frozenset(MODEL_YEAR_CODES[(year - MODEL_YEAR_CYCLE_START) % len(MODEL_YEAR_CODES)]
                   for year in range(first_year, last_year + 1))


@dataclass(frozen=True, kw_only=True)
class VinPattern:
  wmis: frozenset[str]
  descriptor: str
  model_year_codes: frozenset[str]

  def matches(self, vin: Vin) -> bool:
    return vin.wmi in self.wmis and vin.vds.startswith(self.descriptor) and vin.vis[:1] in self.model_year_codes


PlatformPatterns = Mapping[str, tuple[VinPattern, ...]]


@cache
def registered_patterns() -> PlatformPatterns:
  return {str(platform): patterns for platform, patterns in
          get_interface_attr('VIN_PATTERNS', combine_brands=True, ignore_none=True).items()}


def identify_by_vin(vin: str, *, fw_candidates: Collection[str], can_layout: CanLayout,
                    patterns: PlatformPatterns | None = None) -> str | None:
  if not is_valid_vin(vin):
    return None
  candidates = _platforms_matching(Vin(vin), registered_patterns() if patterns is None else patterns)
  if fw_candidates:
    candidates = _narrowed_to(candidates, fw_candidates)
  else:
    candidates = _consistent_with_recorded_can(candidates, can_layout)
  return next(iter(candidates)) if len(candidates) == 1 else None


def _platforms_matching(vin: Vin, patterns: PlatformPatterns) -> set[str]:
  return {platform for platform, platform_patterns in patterns.items() if any(pattern.matches(vin) for pattern in platform_patterns)}


def _narrowed_to(candidates: set[str], fw_candidates: Collection[str]) -> set[str]:
  return candidates & {str(candidate) for candidate in fw_candidates}


def _consistent_with_recorded_can(candidates: set[str], can_layout: CanLayout) -> set[str]:
  tables = {str(car): car for car in all_legacy_fingerprint_cars()}
  return {platform for platform in candidates if platform not in tables or _layout_fits_table(tables[platform], can_layout)}


def _layout_fits_table(platform: str, can_layout: CanLayout) -> bool:
  return any(_survives(platform, can_layout[bus]) for bus in FINGERPRINT_BUSES if can_layout.get(bus))


def _survives(platform: str, messages: Mapping[int, int]) -> bool:
  remaining = [platform]
  for address, length in messages.items():
    if address not in DIAGNOSTIC_ADDRESSES:
      remaining = eliminate_incompatible_cars(CanData(address, bytes(length), 0), remaining)
  return bool(remaining)
