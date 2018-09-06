#ifndef CSCE240_SAMPLES_DEC2HEX_
#define CSCE240_SAMPLES_DEC2HEX_

#include <string>
using std::string;
using std::to_string;

class Dec2Hex {
public:
  string Convert(int decimal);

private:
  string DecDig2HexDig(int dig);
};

#endif
