
#include "main.h"

int main(int argc, char** argv) {
  int decimal = 0;
  cin >> decimal;

  Dec2Hex converter;
  cout << converter.Convert(decimal);

  return 0;
}


