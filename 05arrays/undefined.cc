/* Copyright 2017 */
#include "main.h"


int main(int argc, char** argv) {
  int a[] = {0, 1, 2, 3};
  for (int i = -4; i < 8; ++i) {
    cout << i << " < 8: " << (i < 8 ? "true" : "false") << endl;
    cout << "a[" << i << "]: " << a[i] << endl;
  }

  return 0;
}
