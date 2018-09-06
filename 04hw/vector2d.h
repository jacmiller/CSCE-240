#ifndef _240_04HW_VECTOR2D_H
#define _240_04HW_VECTOR2D_H

#include <cmath>
#include <string>
using std::string;
using std::to_string;
#include <iostream>
using std::ostream;
using std::istream;

namespace csce240 {
class Vector2d {
 private:
    double x_;
    double y_;

 public:
    Vector2d() : x_(0.0), y_(0.0) {}
    Vector2d(double x, double y) : x_(x), y_(y) {}

    inline double x() const { return x_; }

    inline double y() const { return y_; }

    const Vector2d Add(const Vector2d& rhs) const;
    const Vector2d Subtract(const Vector2d& rhs) const;
    const Vector2d Reverse() const;
    const Vector2d Scale(double scalar) const;
    bool EqualTo(const Vector2d& rhs) const;
    bool NotEqualTo(const Vector2d& rhs) const;

    double GetLength() const;
    const Vector2d GetUnit() const;

    const string ToString() const;

    friend const Vector2d operator+(const Vector2d& lhs, const Vector2d& rhs);
    friend const Vector2d operator-(const Vector2d& lhs, const Vector2d& rhs);
    friend const Vector2d operator-(const Vector2d& v);
    friend const Vector2d operator*(const Vector2d& v, double scalar);
    friend const Vector2d operator*(double scalar, const Vector2d& v);
    friend bool operator==(const Vector2d& lhs, const Vector2d& rhs);
    friend bool operator!=(const Vector2d& lhs, const Vector2d& rhs);
    friend ostream& operator<<(ostream& lhs, const Vector2d& rhs);
};

}  // namespace csce240
#endif
