// #define DEFINE_UNIT(unit_name, unit, suffix, system)
#ifndef DEFINE_UNIT
#error "DEFINE_UNIT macro is not defined"
#endif
DEFINE_UNIT(Meter, 1.0, m, Metric)
DEFINE_UNIT(Centimeter, 0.01, cm, Metric)
DEFINE_UNIT(Kilometer, 1000.0, km, Metric)
DEFINE_UNIT(Foot, 0.3048, ft, English)
DEFINE_UNIT(Inch, 0.0254, in, English)
DEFINE_UNIT(Mile, 1609.344, mi, English)
DEFINE_UNIT(Astronomical_Unit, 1.486e11, AU, Astronomical)
DEFINE_UNIT(Light_Year, 9.461e15, ly, Astronomical)
DEFINE_UNIT(Cubit, 0.55, cubit, Archaic)
