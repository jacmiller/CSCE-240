// Baseconverter.cc : Contains functions for conversion

#include "baseconverter.h"

BaseConverter::BaseConverter(int base_10) {
  base_10_ = base_10;
}

int BaseConverter::GetBase10() {
  return base_10_;
}
string GetUnsignedBase2Internal(int base_10, int bits) {
  string base_2;
  int remainder = 0;
  for (int i = 0; i != bits; i++) {
  remainder = base_10 % 2;
  base_2.insert(0, to_string(remainder));
  base_10 /= 2;
  }
  return base_2;
}
string BaseConverter::GetUnsignedBase2(int bits) {
  return GetUnsignedBase2Internal(base_10_, bits);
}
string Complement(const string& bits) {
  string swap(bits);
  for (int i = 0; i < swap.size(); ++i)
  if (swap.at(i) == '0')
  swap.replace(i, 1, "1");
  else
  swap.replace(i, 1, "0");
  return swap;
}
string AddBase2(const string& lhs, const string& rhs) {
  string sum = "";
  unsigned char a, b, c = 0;

  for (int i = lhs.size() - 1; i > -1; --i) {
  a = lhs.at(i) - '0';
  b = rhs.at(i) - '0';
  sum = static_cast<char>(((a ^ b) ^ c) + '0') + sum;
  c = ((a & b) | (a & c)) | (b & c);
  }
  return sum;
}
string ToTwosComplement(string base_2) {
  string inversion = Complement(base_2);

  string one(base_2.size() - 1, '0');
  one += "1";

  return AddBase2(inversion, one);
}
string BaseConverter::GetSignedBase2(int bits) {
  bool neg = 0 > base_10_;
  int base_10 = neg ? base_10_ * -1 : base_10_;
  string base_2 = GetUnsignedBase2Internal(base_10, bits);
  if (neg)
  base_2 = ToTwosComplement(base_2);
  return base_2;
}
string DecDig2HexDig(int dig) {
  if (dig < 10)
  return to_string(dig);
  else
  switch (dig) {
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
string BaseConverter::GetBase16() {
  string hex;

  bool neg = base_10_ < 0;
  base_10_ = neg ? base_10_*-1 : base_10_;

  int digit = 0;
  while (base_10_ > 0) {
  digit = base_10_ % 16;
  hex = DecDig2HexDig(digit) + hex;
  base_10_ /= 16;
  }
  if (neg)
  return "-" + hex;
  else
  return hex;
}

void BaseConverter::SetBase10(int base_10) {
  base_10_ = base_10;
}

void BaseConverter::SetUnsignedBase2(string base_2) {
  int size = static_cast<int>(base_2.size()) - 1;
  base_10_ = 0;
  int pow_2 = 1;

  for (int i = size; i > -1; --i) {
  if (base_2.at(i) == '1')
  base_10_ += pow_2;
  pow_2 *= 2;
  }
}

void BaseConverter::SetSignedBase2(string base_2) {
  base_10_ = 0;

  if (base_2.at(0) == '0')
  BaseConverter::SetUnsignedBase2(base_2);
  else {
  string complement = ToTwosComplement(base_2);
  BaseConverter::SetUnsignedBase2(complement);
  base_10_ *= -1;
  }
}

int Hex2Dec(char c) {
  if ('0' <= c && c <= '9')
  return static_cast<int>(c - '0');

  if ('A' <= c && c <= 'F')
  return 10 + static_cast<int>(c - 'A');

  if ('a' <= c && c <= 'f')
  return 10 + static_cast<int>(c - 'a');

  return numeric_limits<int>::max();
}
void BaseConverter::SetBase16(string base_16) {
  bool neg = base_16.front() == '-';
  if (neg)
  base_16.erase(base_16.begin());
  base_10_ = 0;
  int pow_16 = 1;
  for (int i = static_cast<int>(base_16.size() - 1); i >= 0; --i) {
  base_10_ += pow_16 * Hex2Dec(base_16.at(i));
  pow_16 *= 16;
  }
  if (neg)
  base_10_ *= -1;
}

