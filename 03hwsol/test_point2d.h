#ifndef _240_03HW_TEST_VECTOR2D_H_
#define _240_03HW_TEST_VECTOR2D_H_

#include <iostream>
using std::endl;
using std::cout;

#include "point2d.h"
#include "vector2d.h"

bool TestPointConstructAndAccess();
bool TestPointSubtract();
bool TestPointAdd();
bool TestPointEqualTo();
bool TestPointNotEqualTo();
bool TestPointDistanceToSquared();
bool TestPointDistanceTo();
bool TestPointToString();

int main(int argc, char** argv);

#endif
