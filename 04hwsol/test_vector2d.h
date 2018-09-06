#ifndef _240_03HW_TEST_VECTOR2D_H_
#define _240_03HW_TEST_VECTOR2D_H_

#include <iostream>
using std::endl;
using std::cout;
#include <sstream>
using std::ostringstream;

#include "vector2d.h"
using csce240::Vector2d;

bool TestVectorCreateAndAccess();
bool TestVectorAdd();
bool TestVectorSubtract();
bool TestVectorReverse();
bool TestVectorScale();
bool TestVectorEqualTo();
bool TestVectorNotEqualTo();
bool TestVectorGetLength();
bool TestVectorGetUnit();
bool TestVectorToString();
bool TestVectorExtractOp();

int main(int argc, char** argv);

#endif
