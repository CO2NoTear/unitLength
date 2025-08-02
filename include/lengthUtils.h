#ifndef LENGTH_UTILS_H
#define LENGTH_UTILS_H

#include "lengthUnitsEnums.h"
#include <iostream>
#include <sstream>
#include <string>
using std::string, std::cout, std::endl, std::cin, std::istringstream;
LengthUnit suffixStringToLengthUnit(const string &suffix);
string lengthUnitToSuffixString(const LengthUnit &unit);
double getReal(const string &prompt, const string &reprompt);

#endif
