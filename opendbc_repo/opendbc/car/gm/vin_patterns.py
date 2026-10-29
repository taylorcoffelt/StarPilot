from opendbc.car.gm.values import CAR
from opendbc.car.vin_identity import VinPattern, model_year_codes

VIN_PATTERNS = {
  CAR.CHEVROLET_TRAX: (
    VinPattern(wmis=frozenset({"KL7"}), descriptor="7L", model_year_codes=model_year_codes(2024, 2026)),
  ),
}
