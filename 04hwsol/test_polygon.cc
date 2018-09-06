#include "test_polygon.h"


bool UnitTest::TestInitSuccess() {
  test_points_ = new Point2d[3];
  test_points_[0] = Point2d(0.0, 0.0);
  test_points_[1] = Point2d(0.1, 0.0);
  test_points_[2] = Point2d(0.1, 0.1);

  Polygon poly;
  int status = poly.Init(test_points_, 3);
  delete test_points_;

  return Polygon::k_init_success_ == status;
}

bool UnitTest::TestInitNotPolygon() {
  test_points_ = new Point2d[2];

  Polygon poly;
  int status = poly.Init(test_points_, 2);
  delete test_points_;

  return Polygon::k_init_not_polygon_ == status;
}

bool UnitTest::TestInitNonunique() {
  test_points_ = new Point2d[4];
  test_points_[0] = Point2d(0.0, 0.0);
  test_points_[1] = Point2d(0.1, 0.0);
  test_points_[2] = Point2d(0.0, 0.0);
  test_points_[3] = Point2d(0.0, 0.1);

  Polygon poly;
  int status = poly.Init(test_points_, 4);
  delete test_points_;

  return Polygon::k_init_nonunique_ == status;
}

bool UnitTest::TestInitHasCollinear() {
  test_points_ = new Point2d[4];
  test_points_[0] = Point2d(0.0, 0.0);
  test_points_[1] = Point2d(0.1, 0.0);
  test_points_[2] = Point2d(0.2, 0.0);
  test_points_[3] = Point2d(0.0, 0.1);

  Polygon poly;
  int status = poly.Init(test_points_, 4);
  delete test_points_;

  return Polygon::k_init_has_collinear_ == status;
}

bool UnitTest::TestToString() {
  test_points_ = new Point2d[3];
  test_points_[0] = Point2d(0.0, 0.0);
  test_points_[1] = Point2d(0.1, 0.0);
  test_points_[2] = Point2d(0.1, 0.1);
 
  Polygon poly;
  assert(Polygon::k_init_success_ == poly.Init(test_points_, 3));
  delete test_points_;

  return poly.ToString() == 
         ">(0.000000, 0.000000)->(0.100000, 0.000000)->(0.100000, 0.100000)-";
}

bool UnitTest::TestCopyConstructor() {
  test_points_ = new Point2d[3];
  test_points_[0] = Point2d(0.0, 0.0);
  test_points_[1] = Point2d(0.1, 0.0);
  test_points_[2] = Point2d(0.1, 0.1);

  Polygon *p1 = new Polygon();
  int status = p1->Init(test_points_, 3);
  assert(Polygon::k_init_success_ == status);
  delete test_points_;

  Polygon p2 = *p1;

  string str1(p1->ToString()), str2;
  delete p1;
  return str1 == p2.ToString();
}

bool UnitTest::TestAssignmentOperator() {
  test_points_ = new Point2d[3];
  test_points_[0] = Point2d(0.0, 0.0);
  test_points_[1] = Point2d(0.1, 0.0);
  test_points_[2] = Point2d(0.1, 0.1);

  Polygon *p1 = new Polygon();
  int status = p1->Init(test_points_, 3);
  assert(Polygon::k_init_success_ == status);
  delete test_points_;

  Polygon p2;
  p2 = *p1;
  p2 = p2;

  string str1(p1->ToString()), str2;
  delete p1;
  return str1 == p2.ToString();
}

bool UnitTest::TestOffsetBy() {
  test_points_ = new Point2d[3];
  test_points_[0] = Point2d(0.0, 0.0);
  test_points_[1] = Point2d(0.1, 0.0);
  test_points_[2] = Point2d(0.1, 0.1);

  Polygon poly;
  assert(poly.Init(test_points_, 3) == Polygon::k_init_success_);
  delete test_points_;

  poly.Offset(-Vector2d(-1.0, -1.0));
  return poly.ToString() ==
         ">(1.000000, 1.000000)->(1.100000, 1.000000)->(1.100000, 1.100000)-";
}

bool UnitTest::TestScaleBy() {
  test_points_ = new Point2d[4];
  test_points_[0] = Point2d(0.0, 0.0);
  test_points_[1] = Point2d(1.0, 0.0);
  test_points_[2] = Point2d(1.0, 1.0);
  test_points_[3] = Point2d(0.0, 1.0);

  Polygon p1, p2;
  assert(p1.Init(test_points_, 4) == Polygon::k_init_success_);
  p2 = p1;
  delete test_points_;

  p1.Scale(2, Point2d(0.5, 0.5));
  p2.Scale(0.5, Point2d(0.5, 0.5));
  return p1.ToString() == ">(-1.414214, -1.414214)->(2.414214, -1.414214)->(2.414214, 2.414214)->(-1.414214, 2.414214)-"
         && p2.ToString() == ">(-0.353553, -0.353553)->(1.353553, -0.353553)->(1.353553, 1.353553)->(-0.353553, 1.353553)-";
}

int main(int argc, char** argv) {
  UnitTest tester;

  cout << "Polygon::TestInitSuccess " << endl;
  if (tester.TestInitSuccess())
    cout << "  PASSED" << endl;
  else
    cout << "  FAILED" << endl;

  cout << "Polygon::TestInitNotPolygon " << endl;
  if (tester.TestInitNotPolygon())
    cout << "  PASSED" << endl;
  else
    cout << "  FAILED" << endl;

  cout << "Polygon::TestInitNonunique " << endl;
  if (tester.TestInitNonunique())
    cout << "  PASSED" << endl;
  else
    cout << "  FAILED" << endl;

  cout << "Polygon::TestInitHasCollinear " << endl;
  if (tester.TestInitHasCollinear())
    cout << "  PASSED" << endl;
  else
    cout << "  FAILED" << endl;

  cout << "Polygon::TestOffsetBy " << endl;
  if (tester.TestOffsetBy())
    cout << "  PASSED" << endl;
  else
    cout << "  FAILED" << endl;

  cout << "Polygon::TestScaleBy " << endl;
  if (tester.TestScaleBy())
    cout << "  PASSED" << endl;
  else
    cout << "  FAILED" << endl;

  cout << "Polygon::TestToString " << endl;
  if (tester.TestToString())
    cout << "  PASSED" << endl;
  else
    cout << "  FAILED" << endl;

  cout << "Polygon::TestCopyConstructor " << endl;
  if (tester.TestCopyConstructor())
    cout << "  PASSED" << endl;
  else
    cout << "  FAILED" << endl;

  cout << "Polygon::TestAssignmentOperator " << endl;
  if (tester.TestAssignmentOperator())
    cout << "  PASSED" << endl;
  else
    cout << "  FAILED" << endl;

  return 0;
}

