/* Copyright 2017 */
#include "main.h"


int main(int argc, char** argv) {
  const int size = 4;
  int* a = nullptr;
  a = new int[size];
  for (int i = 0; i < size; ++i) {
    a[i] = i + 1; // (a + i)* =  i + 1;
  }

  int sum = 0;
  for (int i = 0; i < size; ++i) {
    cout << a[i];
	if ( i < size - 1 )
	  cout << " + ";
    sum += a[i];
  }
  cout << " = " << sum << endl;

  return 0;
}
