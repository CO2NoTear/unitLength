#include "length.h"
#include <gtest/gtest.h>

TEST(convertTest, toMeters) {
  Length length;
  auto compareConverted = [&length](const double &val, const string &suffix,
                                    const double &ratio) {
    length.ReadLength(val, suffix);
    auto converted = convertToMeters(length);
    EXPECT_EQ(converted.getVal(), val * ratio)
        << "Failed for value: " << val << " and suffix: " << suffix;
  };

#define DEFINE_UNIT(unit_name, unit, suffix, system)                           \
  compareConverted(111.111, #suffix, unit);
#include "lengthUnitsMacro.h"
#undef DEFINE_UNIT
}
