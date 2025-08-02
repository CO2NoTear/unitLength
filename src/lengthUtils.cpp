#include "lengthUtils.h"
#include "lengthUnitsEnums.h"

LengthUnit suffixStringToLengthUnit(const string &user_suffix) {
#define DEFINE_UNIT(unit_name, unit, suffix, system)                           \
  if (user_suffix == std::string{#suffix}) {                                   \
    return LengthUnit::eLengthUnit_##unit_name;                                \
  }
#include "lengthUnitsMacro.h"
#undef DEFINE_UNIT
  return LengthUnit::eLengthUnit_ERROR;
}

string lengthUnitToSuffixString(const LengthUnit &unit) {
  switch (unit) {
#define DEFINE_UNIT(unit_name, unit, suffix, system)                           \
  case LengthUnit::eLengthUnit_##unit_name:                                    \
    return std::string{#suffix};
#include "lengthUnitsMacro.h"
#undef DEFINE_UNIT
  default:
    return "NOT_A_UNIT";
  }
}

double getReal(const string &prompt, const string &reprompt) {
  while (true) {
    cout << prompt;
    string line;
    if (!getline(cin, line))
      throw std::domain_error("...");
    double val;
    char remain;
    istringstream iss(line);
    if (iss >> val && !(iss >> remain))
      return val;
    cout << reprompt << endl;
  }
}
