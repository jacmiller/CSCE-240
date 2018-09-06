#include <iostream>
  using namespace std;

int main(int args, char** argv) {
  unsigned char a;
  short b;
  int c;
  long d;

  d = c = b = a = 14;

  float y;
  double z;

  y = a / 3.0f;
  z = y*5;

  d = static_cast<long>(z);
  cout << "d = " d << "\n";
  cout << "z = " << z << endl;

  char i;
  i = 'i';

  bool j;
  j = y < z;
  cout << "y < z " << i << "s " << j << endl;
}

