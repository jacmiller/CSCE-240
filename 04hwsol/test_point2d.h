#ifndef _240_03HW_TEST_VECTOR2D_H_
#define _240_03HW_TEST_VECTOR2D_H_

#include <iostream>
using std::endl;
using std::cin;
using std::cout;
#include <sstream>
using std::ostringstream;

#include "point2d.h"
using csce240::Point2d;
#include "vector2d.h"
using csce240::Vector2d;

bool TestPointConstructAndAccess();
bool TestPointSubtract();
bool TestPointAdd();
bool TestPointEqualTo();
bool TestPointNotEqualTo();
bool TestPointDistanceToSquared();
bool TestPointDistanceTo();
bool TestPointToString();
bool TestPointToCout();
bool TestPointFromCin();
bool TestPointExtractOp();

int main(int argc, char** argv);

#endif
