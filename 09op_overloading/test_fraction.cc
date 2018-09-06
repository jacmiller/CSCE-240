#include "test_fraction.h"

int main(int argc, char** argv) {
  Fraction f1(2, 4), f2(3, 9);

  cout << f1 << " + " << f2 << " = " << (f1 + f2) << endl;
  cout << f1 << " - " << f2 << " = " << (f1 - f2) << endl;

  cout << "Enter a fraction in the form \"num den\": ";
  Fraction f3(0,1);

  cin >> f3;
  cout << "You entered " << f3 << endl;

  cout << 3 << " + " << f3 << " = " << (3 + f3) << endl;

  string buff;
  cin >> buff;
  cout << "You left " << buff << " in the stream!" << endl;


  return 0;
}

istream& operator>>(istream& lhs, Fraction& rhs) {
  // step 1: get num
  char byte;
  string num = "";
  lhs.get(byte);
  while (byte != '/') {
    assert(('0' <= byte && byte <= '9') || byte == ' ');

    num += byte;
    lhs.get(byte);
  }

  // step 2: get den
  lhs.get(byte);
  while (byte == ' ')
    lhs.get(byte);

  string den = "";
  while ('0' <= byte && byte <= '9') {
    den += byte;
    lhs.get(byte);
  }
  lhs.putback(byte);

  // step 3: profit
  rhs = Fraction(stoi(num), stoi(den));
  
  return lhs;
}

