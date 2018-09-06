#include "vector2d.h"

const Vector2d operator+(const Vector2d& lhs, const Vector2d& rhs) {
  return lhs.Add(rhs);
}
const Vector2d Vector2d::Add(const Vector2d& rhs) const {
  return Vector2d(x_ + rhs.x_, y_ + rhs.y_);
}

const Vector2d operator-(const Vector2d& lhs, const Vector2d& rhs) {
  return lhs.Subtract(rhs);
}
const Vector2d Vector2d::Subtract(const Vector2d& rhs) const {
  return Vector2d(x_ - rhs.x_, y_ - rhs.y_);
}

const Vector2d operator-(const Vector2d& rhs) {
  return rhs.Reverse();
}
const Vector2d Vector2d::Reverse() const {
  return Vector2d(-x_, -y_);
}

const Vector2d operator*(const Vector2d& lhs, double rhs) {
  return Vector2d(lhs.x_*rhs, lhs.y_*rhs);
}
const Vector2d operator*(double lhs, const Vector2d& rhs) {
  return rhs*lhs;
}
const Vector2d Vector2d::Scale(double scalar) const {
  return Vector2d(x_ * scalar, y_ * scalar);
}

bool operator==(const Vector2d& lhs, const Vector2d& rhs) {
  return lhs.EqualTo(rhs);
}
bool Vector2d::EqualTo(const Vector2d& rhs) const {
  if (x_ == rhs.x_ && y_ == rhs.y_)
    return true;
  else
    return false;
}

bool operator!=(const Vector2d& lhs, const Vector2d& rhs) {
  return lhs.NotEqualTo(rhs);
}
bool Vector2d::NotEqualTo(const Vector2d& rhs) const {
  return !EqualTo(rhs);
}

double Vector2d::GetLength() const {
  double magnitude;
  magnitude = sqrt(pow(x_, 2) + (pow(y_, 2)));
  return magnitude;
}

const Vector2d Vector2d::GetUnit() const {
  return Vector2d(x_ / GetLength(), y_ / GetLength());
}

const string Vector2d::ToString() const {
  return "(" + to_string(x_) + ", " + to_string(y_) + ")";
}
