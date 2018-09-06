#include "test_point2d.h"


int main(int argc, char** argv) {
  int passed = 0;

  if (TestPointConstructAndAccess())
    ++passed;

  if (TestPointSubtract())
    ++passed;

  if (TestPointAdd())
    ++passed;

  if (TestPointEqualTo())
    ++passed;

  if (TestPointNotEqualTo())
    ++passed;

  if (TestPointDistanceToSquared())
    ++passed;

  if (TestPointDistanceTo())
    ++passed;

  if (TestPointToString())
    ++passed;

  cout << passed << " of 8 tests passed." << endl;

  return 0;
}

bool TestPointConstructAndAccess() {
  cout << "TestPointConstructAndAccess" << endl;
  Point2d p1, p2(1.5, 2.3);
  cout << "  EXPECTED: 0, 0 ACTUAL: ";
  cout << p1.x() << ", " << p1.y() << endl;
  cout << "  EXPECTED: 1.5, 2.3 ACTUAL: ";
  cout << p2.x() << ", " << p2.y() << endl;

  bool pass = p1.x() == 0.0 && p1.y() == 0.0 && p2.x() == 1.5 && p2.y() == 2.3;
  cout << "  " << (pass ? "PASSED" : "FAILED") << endl;
  return pass;
}

bool TestPointSubtract() {
  cout << "TestPointSubtract" << endl;
  Point2d p1(1.0, -3.0), p2(0.5, 1.5);

  Vector2d v1 = p1.Subtract(p2);
  cout << "  EXPECTED: 0.5, -4.5 ACTUAL: ";
  cout << v1.x() << ", " << v1.y() << endl;

  Vector2d v2 = p2 - p1;
  cout << "  EXPECTED: -0.5, 4.5 ACTUAL: ";
  cout << v2.x() << ", " << v2.y() << endl;

  bool pass = v1.x() == 0.5 && v1.y() == -4.5 && v2.x() == -0.5 &&
              v2.y() == 4.5;
  cout << "  " << (pass ? "PASSED" : "FAILED") << endl;
  return pass;
}

bool TestPointAdd() {
  cout << "TestPointAdd" << endl;
  Point2d p1(0.0, 0.0), p2;
  Vector2d v1(4.0, 6.0);

  p2 = p1.Add(v1);
  cout << "  EXPECTED: 4, 6 ACTUAL: ";
  cout << p2.x() << ", " << p2.y() << endl;

  p2 = p1 + v1;
  cout << "  EXPECTED: 4, 6 ACTUAL: ";
  cout << p2.x() << ", " << p2.y() << endl;

  bool pass = p2.x() == 4.0 && p2.y() == 6.0;
  cout << "  " << (pass ? "PASSED" : "FAILED") << endl;
  return pass;
}

bool TestPointEqualTo() {
  cout << "TestPointEquals:" << endl;
  Point2d p1(1.0, 1.0), p2(2.0, 1.0), p3(1.0, 2.0);
  
  cout << "  EXPECTED (1.0, 1.0) == (1.0, 1.0): true ACTUAL: ";
  cout << (p1.EqualTo(p1) ? "true" : "false") << endl;
  cout << "  EXPECTED (1.0, 1.0) == (2.0, 1.0): false ACTUAL: ";
  cout << ((p1 == p2) ? "true" : "false") << endl;
  cout << "  EXPECTED (1.0, 1.0) == (1.0, 2.0): false ACTUAL: ";
  cout << ((p1 == p3) ? "true" : "false") << endl;

  bool pass = p1.EqualTo(p1) && p1 != p2 && p1 != p3;
  cout << "  " << (pass ? "PASSED" : "FAILED") << endl;
  return pass;
}

bool TestPointNotEqualTo() {
  cout << "TestPointNotEqualTo:" << endl;
  Point2d p1(1.0, 1.0), p2(2.0, 1.0), p3(1.0, 2.0);
  
  cout << "  EXPECTED (1.0, 1.0) != (1.0, 1.0): false ACTUAL: ";
  cout << (p1.NotEqualTo(p1) ? "true" : "false") << endl;
  cout << "  EXPECTED (1.0, 1.0) == (2.0, 1.0): true ACTUAL: ";
  cout << ((p1 != p2) ? "true" : "false") << endl;
  cout << "  EXPECTED (1.0, 1.0) == (1.0, 2.0): true ACTUAL: ";
  cout << ((p1 != p3) ? "true" : "false") << endl;

  bool pass = !p1.NotEqualTo(p1) && p1 != p2 && p1 != p3;
  cout << "  " << (pass ? "PASSED" : "FAILED") << endl;
  return pass;
}

bool TestPointDistanceToSquared() {
  cout << "TestPointDistanceToSquared:" << endl;
  Point2d p1(0.0, 0.0), p2(3.0, 4.0);

  cout << "  EXPECTED (0, 0) to (3, 4): 25 ACTUAL: " <<
          p1.DistanceToSquared(p2) << endl;

  bool pass = p1.DistanceToSquared(p2) == 25;
  cout << "  " << (pass ? "PASSED" : "FAILED") << endl;
  return pass;
}

bool TestPointDistanceTo() {
  cout << "TestPointDistanceTo:" << endl;
  Point2d p1(0.0, 0.0), p2(3.0, 4.0);

  cout << "  EXPECTED (0, 0) to (3, 4): 5 ACTUAL: " << p1.DistanceTo(p2) <<
          endl;

  bool pass = p1.DistanceTo(p2) == 5;
  cout << "  " << (pass ? "PASSED" : "FAILED") << endl;
  return pass;
}

bool TestPointToString() {
  cout << "TestPointToString:" << endl;
  Point2d p(3.7, -8.1);

  cout << "  EXPECTED: (3.700000, -8.100000) ACTUAL: ";
  cout << p.ToString() << endl;

  bool pass = "(3.700000, -8.100000)" == p.ToString();
  cout << "  " << (pass ? "PASSED" : "FAILED") << endl;
  return pass;
}

