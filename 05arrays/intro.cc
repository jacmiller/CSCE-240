/* Copyright 2017 */
#include "main.h"


int main(int argc, char** argv) {
  const int kSize = 4;
  int a[kSize];

  for (int i = 0; i < kSize; ++i)
    a[i] = i + 1;

  int sum = 0;
  for (int i = 0; i < kSize; ++i) {
    cout << a[i];
	if ( i < kSize - 1 )
	  cout << " + ";
    sum += a[i];
  }
  cout << " = " << sum << endl;

  int b[] = {0, 1, 2, 3};
  for (int i = 0; i < kSize; ++i)
    cout << "b[" << i << "]: " << b[i] << endl;

  return 0;
}
