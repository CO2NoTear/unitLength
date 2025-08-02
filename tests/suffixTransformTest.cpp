#include "lengthUnitsEnums.h"
#include "lengthUtils.h"
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(SuffixToEnumTest, BasicAssertions) {
  EXPECT_STREQ(
      "cm",
      lengthUnitToSuffixString(LengthUnit::eLengthUnit_Centimeter).c_str());
}
TEST(EnumToSuffix, BasicAssertions) {
  EXPECT_EQ(LengthUnit::eLengthUnit_Centimeter, suffixStringToLengthUnit("cm"));
}
