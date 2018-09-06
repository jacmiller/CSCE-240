#include "fraction.h"

int Fraction::num() const {
  return num_;
}

int Fraction::den() const {
  return den_;
}

const Fraction Fraction::Add(const Fraction& rhs) const {
  return Fraction(num_*rhs.den_ + rhs.num_*den_, rhs.den_*den_);
}

const Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
  return Fraction(lhs.num_*rhs.den_ + rhs.num_*lhs.den_, rhs.den_*lhs.den_);
}

const Fraction Fraction::operator-(const Fraction& rhs) const {
  return Fraction(num_*rhs.den_ - rhs.num_*den_, rhs.den_*den_);
}

ostream& operator<<(ostream& lhs, const Fraction& rhs) {
  lhs << rhs.num_ << "/" << rhs.den_;
  return lhs;
}

