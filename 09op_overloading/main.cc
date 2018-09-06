#include "main.h"

int main(int argc, char** argv) {
  Fraction f1(2, 4), f2(3, 9);

  cout << f1 << " + " << f2 << " = " << (f1 + f2) << endl;
  cout << f1 << " - " << f2 << " = " << (f1 - f2) << endl;

  cout << "Enter a fraction in the form \"num den\": ";
  cin >> f1;
  cout << "You entered " << f1 << endl;
  
  return 0;
}

istream& operator>>(istream& lhs, Fraction& rhs) {
  int num, den;
  lhs >> num >> den;

  rhs = Fraction(num, den);
  return lhs;
}


