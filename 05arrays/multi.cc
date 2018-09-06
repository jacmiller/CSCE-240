/* Copyright 2017 */
#include "main.h"


int main(int argc, char** argv) {
  const int rows = 4;
  const int cols = 3;

  int a[rows][cols];
  for (int i = 0; i < rows; ++i)
    for (int j = 0; j < cols; ++j)
    	a[i][j] = (i + 1)*(j - 1);

  for (int i = 0; i < rows; ++i) { //selects row

    for (int j = 0; j < cols; ++j) // prints columns
	  cout << a[i][j] << '\t';

    cout << endl;
  }

  return 0;
}
