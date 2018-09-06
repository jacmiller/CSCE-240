#ifndef _240_LECT_09OP_OVERLOADING_H_
#define _240_LECT_09OP_OVERLOADING_H_

#include <iostream>
using std::endl;
using std::cin;
using std::cout;
using std::istream;

#include "fraction.h"

int main(int argc, char** argv);

istream& operator>>(istream& lhs, Fraction& rhs);

#endif
