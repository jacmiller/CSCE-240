#include "point2d.h"
using csce240::Point2d;

namespace csce240 {
  const double threshold = 1.0 / 100000.0;
  inline bool equal(double a, double b) {
    return fabs(a - b) < threshold;
  }

  bool Point2d::Collinear(const Point2d& a,
    const Point2d& b, const Point2d& c) {
    return equal(0.0, (b.x() - a.x()) * (c.y() - a.x())
      - (c.x() - a.x()) * (b.y() - a.y()));
  }

  const Vector2d operator-(const Point2d& lhs, const Point2d& rhs) {
    return lhs.Subtract(rhs);
  }
  const Vector2d Point2d::Subtract(const Point2d& rhs) const {
    return Vector2d(x_ - rhs.x_, y_ - rhs.y_);
  }

  const Point2d operator+(const Point2d& lhs, const Vector2d& rhs) {
    return lhs.Add(rhs);
  }
  const Point2d Point2d::Add(const Vector2d& rhs) const {
    return Point2d(x_ + rhs.x(), y_ + rhs.y());
  }

  bool operator==(const Point2d& lhs, const Point2d& rhs) {
    return lhs.EqualTo(rhs);
  }
  bool Point2d::EqualTo(const Point2d& rhs) const {
    if (x_ == rhs.x_ && y_ == rhs.y_)
      return true;
    else
      return false;
  }

  bool operator!=(const Point2d& lhs, const Point2d& rhs) {
    return lhs.NotEqualTo(rhs);
  }
  bool Point2d::NotEqualTo(const Point2d& rhs) const {
    return !EqualTo(rhs);
  }

  double Point2d::DistanceToSquared(const Point2d& to) const {
    double x = pow(to.x_ - x_, 2);
    double y = pow(to.y_ - y_, 2);
    return x + y;
  }

  double Point2d::DistanceTo(const Point2d& to) const {
    return sqrt(DistanceToSquared(to));
  }

  const string Point2d::ToString() const {
    return "(" + to_string(x_) + ", " + to_string(y_) + ")";
  }
  ostream& operator<< (ostream& lhs, const Point2d& rhs) {
    lhs << "(" << rhs.x_ << ", " << rhs.y_ << ")";
    return lhs;
  }
  istream& operator >> (istream& lhs, Point2d& rhs) {
    lhs >> rhs.x_ >> rhs.y_;
    return lhs;
  }
}  // namespace csce240
