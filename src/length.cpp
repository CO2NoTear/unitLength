#include "length.h"
#include "lengthUtils.h"
#include <iomanip>

using std::fixed, std::setprecision, std::ostream;

void Length::ReadLength(const double &val, const string &suffix) {
  // convert suffix to LengthUnit
  LengthUnit unit = suffixStringToLengthUnit(suffix);
  if (unit == LengthUnit::eLengthUnit_ERROR) {
    throw std::domain_error("Invalid length unit: " + suffix);
  }
  val_ = val;
  unit_ = unit;
}

ostream &operator<<(ostream &os, const Length &l) {
  switch (l.unit_) {
#define DEFINE_UNIT(unit_name, unit, suffix, system)                           \
  case LengthUnit::eLengthUnit_##unit_name:                                    \
    os << fixed << setprecision(l.precision_) << l.val_ << #suffix << " ("     \
       << l.val_ << " " << #unit_name << ")";                                  \
    break;
#include "lengthUnitsMacro.h"
#undef DEFINE_UNIT
  default:
    break;
  }
  return os;
}

string getUnitType(const Length &l) {
  switch (l.unit_) {
#define DEFINE_UNIT(unit_name, unit, suffix, system)                           \
  case LengthUnit::eLengthUnit_##unit_name:                                    \
    return std::string{#system};
#include "lengthUnitsMacro.h"
#undef DEFINE_UNIT
  default:
    return "ERROR";
  }
}

Length convertToMeters(const Length &l) {
  Length result;

  switch (l.unit_) {
#define DEFINE_UNIT(unit_name, unit, suffix, system)                           \
  case LengthUnit::eLengthUnit_##unit_name:                                    \
    result.ReadLength(l.val_ *unit, "m");                                      \
    break;
#include "lengthUnitsMacro.h"
#undef DEFINE_UNIT
  default:
    throw std::domain_error("Invalid length unit for conversion: " +
                            lengthUnitToSuffixString(l.unit_));
  }
  return result;
}
