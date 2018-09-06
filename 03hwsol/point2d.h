#ifndef _240_03HW_POINT2D_H
#define _240_03HW_POINT2D_H

#include <cmath>
#include <string>
using std::string;

#include "vector2d.h"

class Point2d {
 private:
  double x_;
  double y_;

 public:
  Point2d() : x_(0.0), y_(0.0) {}

  Point2d(double x, double y) : x_(x), y_(y) {}

  inline double x() const { return x_; }

  inline double y() const { return y_; }

  const Vector2d Subtract(const Point2d& rhs) const;
  const Point2d Add(const Vector2d& rhs) const;
  bool EqualTo(const Point2d& rhs) const;
  bool NotEqualTo(const Point2d& rhs) const;
  double DistanceToSquared(const Point2d& to) const;
  double DistanceTo(const Point2d& to) const;

  const string ToString() const;

  friend const Vector2d operator-(const Point2d& lhs, const Point2d& rhs);
  friend const Point2d operator+(const Point2d& lhs, const Vector2d& rhs);
  friend bool operator==(const Point2d& lhs, const Point2d& rhs);
  friend bool operator!=(const Point2d& lhs, const Point2d& rhs);
};
#endif
