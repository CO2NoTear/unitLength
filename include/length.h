#ifndef LENGTH_H
#define LENGTH_H

#include "lengthUnitsEnums.h"
#include "lengthUtils.h"
#include <cstdint>
#include <string>
using std::string;
class Length {
  double val_;
  LengthUnit unit_;
  uint8_t precision_ = 2; // Default precision for output

public:
  inline void setPrecision(const uint8_t &precision) { precision_ = precision; }
  inline uint8_t getPrecision() const { return precision_; }
  inline double getVal() const { return val_; }
  void ReadLength(const double &val, const string &suffix);
  friend std::ostream &operator<<(std::ostream &os, const Length &l);
  friend string getUnitType(const Length &l);
  friend Length convertToMeters(const Length &l);
};

#endif
