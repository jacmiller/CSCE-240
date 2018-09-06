#include "test_vector2d.h"


int main(int argc, char** argv) {
  int passed = 0;

  if (TestVectorCreateAndAccess())
    ++passed;

  if (TestVectorAdd())
    ++passed;

  if (TestVectorSubtract())
    ++passed;

  if (TestVectorReverse())
    ++passed;

  if (TestVectorScale())
    ++passed;

  if (TestVectorEqualTo())
    ++passed;

  if (TestVectorNotEqualTo())
    ++passed;

  if (TestVectorGetLength())
    ++passed;

  if (TestVectorGetUnit())
    ++passed;

  if (TestVectorToString())
    ++passed;

  if (TestVectorExtractOp())
    ++passed;

  cout << passed << " of 11 tests passed." << endl; 
  return 0;
}

bool TestVectorCreateAndAccess() {
  cout << "TestVectorCreateAndAccess" << endl;
  Vector2d v1, v2(1.5, 2.3);
  cout << "  EXPECTED: 0, 0 ACTUAL: ";
  cout << v1.x() << ", " << v1.y() << endl;
  cout << "  EXPECTED: 1.5, 2.3 ACTUAL: ";
  cout << v2.x() << ", " << v2.y() << endl;

  bool pass = v1.x() == 0.0 && v1.y() == 0.0 && v2.x() == 1.5 && v2.y() == 2.3;
  cout << "  " << (pass ? "PASSED" : "FAILED") << endl;
  return pass;
}

bool TestVectorAdd() {
  cout << "TestVectorAdd" << endl;
  Vector2d v1(1.7, -3.0), v2(2.1, 1.5);

  Vector2d t1 = v1.Add(v2);
  cout << "  EXPECTED: 3.8, -1.5 ACTUAL: ";
  cout << t1.x() << ", " << t1.y() << endl;

  Vector2d t2 = v1 + v2;
  cout << "  EXPECTED: 3.8, -1.5 ACTUAL: ";
  cout << t2.x() << ", " << t2.y() << endl;

  bool pass = t1.x() == 3.8 && t1.y() == -1.5 && t2.x() == 3.8 &&
              t2.y() == -1.5;
  cout << "  " << (pass ? "PASSED" : "FAILED") << endl;
  return pass;
}

bool TestVectorSubtract() {
  cout << "TestVectorSubtract" << endl;
  Vector2d v1(1.0, -3.0), v2(0.5, 1.5);

  Vector2d t1 = v1.Subtract(v2);
  cout << "  EXPECTED: 0.5, -4.5 ACTUAL: ";
  cout << t1.x() << ", " << t1.y() << endl;

  Vector2d t2 = v2 - v1;
  cout << "  EXPECTED: -0.5, 4.5 ACTUAL: ";
  cout << t2.x() << ", " << t2.y() << endl;

  bool pass = t1.x() == 0.5 && t1.y() == -4.5 && t2.x() == -0.5 &&
              t2.y() == 4.5;
  cout << "  " << (pass ? "PASSED" : "FAILED") << endl;
  return pass;
}

bool TestVectorReverse() {
  cout << "TestVectorReverse" << endl;
  Vector2d v(-1.0, 2.0);

  Vector2d nv1 = v.Reverse();
  cout << "  EXPECTED: 1, -2 ACTUAL: ";
  cout << nv1.x() << ", " << nv1.y() << endl;

  Vector2d nv2 = -nv1;
  cout << "  EXPECTED: -1, 2 ACTUAL: ";
  cout << nv2.x() << ", " << nv2.y() << endl;

  bool pass = nv1.x() == 1.0 && nv1.y() == -2.0 && nv2.x() == -1.0 &&
              nv2.y() == 2.0;
  cout << "  " << (pass ? "PASSED" : "FAILED") << endl;
  return pass;
}

bool TestVectorScale() {
  cout << "TestVectorScale" << endl;
  Vector2d v1(2.0, 4.0);

  Vector2d v2 = v1.Scale(2.0);
  cout << "  EXPECTED 4, 8 ACTUAL: ";
  cout << v2.x() << ", " << v2.y() << endl;

  Vector2d v3 = 0.5*v1;
  cout << "  EXPECTED 1, 2 ACTUAL: ";
  cout << v3.x() << ", " << v3.y() << endl;

  Vector2d v4 = v2*0.5;
  cout << "  EXPECTED 2, 4 ACTUAL: ";
  cout << v4.x() << ", " << v4.y() << endl;

  bool pass = v2.x() == 4.0 && v2.y() == 8.0 && v3.x() == 1.0 &&
              v3.y() == 2.0 && v4.x() == 2.0 && v4.y() == 4.0;
  cout << "  " << (pass ? "PASSED" : "FAILED") << endl;
  return pass;
}

bool TestVectorEqualTo() {
  cout << "TestVectorEqualTo:" << endl;
  Vector2d v1(1.0, 1.0), v2(2.0, 1.0), v3(1.0, 2.0);
  
  cout << "  EXPECTED (1.0, 1.0) == (1.0, 1.0): 1 ACTUAL: ";
  cout << v1.EqualTo(v1) << endl;
  cout << "  EXPECTED (1.0, 1.0) == (2.0, 1.0): 0 ACTUAL: ";
  cout << (v1 == v2) << endl;
  cout << "  EXPECTED (1.0, 1.0) == (1.0, 2.0): 0 ACTUAL: ";
  cout << (v1 == v3) << endl;

  bool pass = v1.EqualTo(v1) && v1 != v2 && v1 != v3;
  cout << "  " << (pass ? "PASSED" : "FAILED") << endl;
  return pass;
}

bool TestVectorNotEqualTo() {
  cout << "TestVectorNotEqualTo:" << endl;
  Vector2d v1(1.0, 1.0), v2(2.0, 1.0), v3(1.0, 2.0);
  
  cout << "  EXPECTED (1.0, 1.0) != (1.0, 1.0): 0 ACTUAL: ";
  cout << v1.NotEqualTo(v1) << endl;
  cout << "  EXPECTED (1.0, 1.0) == (2.0, 1.0): 1 ACTUAL: ";
  cout << (v1 != v2) << endl;
  cout << "  EXPECTED (1.0, 1.0) == (1.0, 2.0): 1 ACTUAL: ";
  cout << (v1 != v3) << endl;

  bool pass = !v1.NotEqualTo(v1) && v1 != v2 && v1 != v3;
  cout << "  " << (pass ? "PASSED" : "FAILED") << endl;
  return pass;
}

bool TestVectorGetLength() {
  cout << "TestVectorGetLength:" << endl;
  Vector2d v1(3, 4);

  cout << "  EXPECTED |(3, 4)|: 5 ACTUAL: " << v1.GetLength() << endl;

  bool pass = v1.GetLength() == 5;
  cout << "  " << (pass ? "PASSED" : "FAILED") << endl;
  return pass;
}

bool TestVectorGetUnit() {
  cout << "TestVectorGetUnit:" << endl;
  Vector2d v1(3, 4), v2 = v1.GetUnit();

  cout << "  EXPECTED UNIT(3, 4): (0.6, 0.8) ACTUAL: ";
  cout << "(" << v2.x() << ", " << v2.y() << ")" << endl;

  bool pass = v2.x() == 0.6 && v2.y() == 0.8;
  cout << "  " << (pass ? "PASSED" : "FAILED") << endl;
  return pass;
}

bool TestVectorToString() {
  cout << "TestVectorToString:" << endl;
  Vector2d v(3.7, -8.1);

  cout << "  EXPECTED: (3.700000, -8.100000) ACTUAL: ";
  cout << v.ToString() << endl;

  bool pass = "(3.700000, -8.100000)" == v.ToString();
  cout << "  " << (pass ? "PASSED" : "FAILED") << endl;
  return pass;
}

bool TestVectorExtractOp() {
  cout << "TestVectorExtractOp:" << endl;
  Vector2d v(-17.801, 6.199);

  cout << "  EXPECTED: (-17.801, 6.199) ACTUAL: ";
  cout << v << endl;

  ostringstream oss;
  oss << v;
  bool pass = "(-17.801, 6.199)" == oss.str();
  cout << "  " << (pass ? "PASSED" : "FAILED") << endl;
  return pass;
}

