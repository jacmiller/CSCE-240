#ifndef _240_04HW_TEST_POLYGON_H_
#define _240_04HW_TEST_POLYGON_H_

#include <iostream>
using std::endl;
using std::cout;

#include "point2d.h"
using csce240::Point2d;
#include "polygon.h"
using csce240::Polygon;
#include "vector2d.h"
using csce240::Vector2d;

class UnitTest {
 public:
  bool TestInitSuccess();
  bool TestInitNotPolygon();
  bool TestInitNonunique();
  bool TestInitHasCollinear();

  bool TestOffsetBy();
  bool TestScaleBy();

  bool TestToString();

  bool TestCopyConstructor();
  bool TestAssignmentOperator();

 private:
  Point2d *test_points_;
};

int main(int, char**);

#endif
