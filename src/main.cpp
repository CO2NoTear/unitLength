#include "length.h"
#include "lengthUnitsEnums.h"
#include "lengthUtils.h"
#include <iostream>
using std::cout, std::endl;

int main(int argc, char *argv[]) {
  Length length;
  length.ReadLength(10.121123847, "mi");
  cout << length << endl;
  return 0;
}
