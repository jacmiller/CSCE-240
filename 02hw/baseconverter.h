#ifndef _02HW_BASECONVERTER_H_
#define _02HW_BASECONVERTER_H_

#include<limits>
using std::numeric_limits;
#include <string>
using std::string;
using std::to_string;

class BaseConverter {
 private:
  int base_10_;


 public:
  BaseConverter(int base_10);

  int GetBase10();

  string GetUnsignedBase2(int bits);

  string GetSignedBase2(int bits);

  string GetBase16();

  void SetBase10(int base_10);

  void SetUnsignedBase2(string base_2);

  void SetSignedBase2(string base_2);

  void SetBase16(string base_16);
};
#endif  // _02HW_BASECONVERTER_H_
