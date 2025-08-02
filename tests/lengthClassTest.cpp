#include "length.h"
#include <gtest/gtest.h>
#include <iomanip>
#include <sstream>

TEST(testLengthClassBasicIO, basicAssertions) {
  Length length;

  auto readLength = [&length](const double &val, const string &suffix,
                              const string &unit_name) {
    length.ReadLength(val, suffix);
    std::ostringstream oss;
    oss << length;

    std::ostringstream expected_result;
    expected_result << std::fixed << std::setprecision(length.getPrecision())
                    << val << suffix << " (" << val << " " << unit_name << ")";
    EXPECT_STREQ(oss.str().c_str(), expected_result.str().c_str())
        << "Failed for value: " << val << " and suffix: " << suffix
        << " on precision: " << length.getPrecision();
  };

  readLength(10.0, "cm", "Centimeter");
  readLength(0.0, "m", "Meter");
  readLength(11.334, "km", "Kilometer");
  readLength(500.0, "mi", "Mile");
  readLength(1.234, "in", "Inch");
  readLength(11.355, "AU", "Astronomical_Unit");
  readLength(10000.350, "ly", "Light_Year");
  readLength(1e9, "cubit", "Cubit");
}

TEST(testLengthClassUnitSystem, basicAssertions) {
  Length length;

  auto getUnitTypeTest = [&length](const double &val, const string &suffix,
                                   const string &system) {
    length.ReadLength(val, suffix);
    auto unit_type = getUnitType(length);

    EXPECT_STREQ(unit_type.c_str(), system.c_str())
        << "Failed for value: " << val << " and suffix: " << suffix;
  };

  getUnitTypeTest(10.0, "cm", "Metric");
  getUnitTypeTest(0.0, "m", "Metric");
  getUnitTypeTest(11.334, "km", "Metric");
  getUnitTypeTest(500.0, "mi", "English");
  getUnitTypeTest(1.234, "in", "English");
  getUnitTypeTest(11.355, "AU", "Astronomical");
  getUnitTypeTest(10000.350, "ly", "Astronomical");
  getUnitTypeTest(1e9, "cubit", "Archaic");
}
