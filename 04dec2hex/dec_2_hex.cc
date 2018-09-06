#include "dec_2_hex.h"

string Dec2Hex::Convert(int decimal) {
  string hex;

  bool neg = decimal < 0;
  decimal = neg ? decimal*-1 : decimal;

  // As long as decimal is not 0
  int digit = 0;
  while ( decimal > 0 ) {
  // extract lowest hex digit
    digit = decimal % 16;
  // prepend to the hex string
    hex.insert(0, DecDig2HexDig(digit));
  // shift by a 16's place
    decimal /= 16;
  }

  if (neg)
    return "-" + hex;
  else
    return hex;	
}

string Dec2Hex::DecDig2HexDig(int dig) {
  if ( dig < 10 )
      return to_string(dig);
    else
      switch(dig) {
      case 10:
        return "A";
      case 11:
  	  return "B";
  	case 12:
  	  return "C";
  	case 13:
  	  return "D";
  	case 14:
  	  return "E";
  	case 15:
  	  return "F";
  	default:
  	  return "";
  }
}

