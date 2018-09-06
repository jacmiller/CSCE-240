#ifndef _240_03HW_TEST_VECTOR2D_H_
#define _240_03HW_TEST_VECTOR2D_H_

#include <iostream>
using std::endl;
using std::cout;

#include "vector2d.h"

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

int main(int argc, char** argv);

#endif
