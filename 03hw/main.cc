#include "main.h"

Point2d GetPoint() {
  double x, y;
  cin >> x >> y;
  return Point2d(x, y);
}
Vector2d GetVector() {
  double x, y;
  cin >> x >> y;
  return Vector2d(x, y);
}
void GenerateInterface() {
  cout << "Point/Vector Calculator" << endl;
  cout << "1.) Point - Point" << endl;
  cout << "2.) Point + Vector" << endl;
  cout << "3.) Vector + Vector" << endl;
  cout << "4.) double * Vector" << endl;
  cout << "5.) Point == Point" << endl;
  cout << "6.) Vector == Vector" << endl;
  cout << "7.) quit" << endl;
}

int main() {
  GenerateInterface();

  int inputnumber;
  cin >> inputnumber;

  while (inputnumber != 7) {
    Point2d p1, p2;
    Vector2d p3, p4;
    double scalar;
    switch (inputnumber) {
    case 1:
      cout << "Subtract Points" << endl;
      p1 = GetPoint();
      p2 = GetPoint();
      cout << (p1 - p2).ToString() << endl << endl << endl;
      break;
    case 2:
      cout << "Add Vector To Point" << endl;
      p3 = GetVector();
      p1 = GetPoint();
      cout << (p1 + p3).ToString() << endl << endl << endl;
      break;
    case 3:
      cout << "Add Vectors" << endl;
      p3 = GetVector();
      p4 = GetVector();
      cout << (p3 + p4).ToString() << endl << endl << endl;
      break;
    case 4:
      cout << "Scale Vector" << endl;
      cin >> scalar;
      p3 = GetVector();
      cout << (scalar * p3).ToString() << endl << endl << endl;
      break;
    case 5:
      cout << "Test Point Equality" << endl;
      p1 = GetPoint();
      p2 = GetPoint();
      if (p1 == p2)
        cout << "true" << endl << endl << endl;
      else
        cout << "false" << endl << endl << endl;
      break;
    case 6:
      cout << "Test Vector Equality" << endl;
      p3 = GetVector();
      p4 = GetVector();
      if (p3 == p4)
        cout << "true" << endl << endl << endl;
      else
        cout << "false" << endl << endl << endl;
      break;
    }
    GenerateInterface();
    cin >> inputnumber;
  }
}
