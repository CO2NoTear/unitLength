#ifndef LENGTH_UNIT_ENUMS_H
#define LENGTH_UNIT_ENUMS_H
enum LengthUnit {
#define DEFINE_UNIT(unit_name, unit, suffix, system) eLengthUnit_##unit_name,
#include "lengthUnitsMacro.h"
#undef DEFINE_UNIT
  eLengthUnit_ERROR,
};
#endif
