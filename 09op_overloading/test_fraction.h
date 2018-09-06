#ifndef _240_LECT_09OP_OVERLOADING_TEST_FRACTION_H_
#define _240_LECT_09OP_OVERLOADING_TEST_FRACTION_H_

#include <cassert>
#include <iostream>
using std::endl;
using std::cin;
using std::cout;
using std::istream;
#include <string>
using std::stoi;
using std::string;

#include "fraction.h"

int main(int argc, char** argv);

istream& operator>>(istream& lhs, Fraction& rhs);

#endif
