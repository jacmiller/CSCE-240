#ifndef _240_LECT_09OP_OVERLOADING_FRACTION_H_
#define _240_LECT_09OP_OVERLOADING_FRACTION_H_

#include <cassert>
#include <iostream>
using std::cout;
using std::ostream;


class Fraction {
 public:
  /*
   * @Asserts den is not 0.
   */
  Fraction(int num, int den) : num_(num), den_(den) { assert(den != 0); };
  Fraction(int num) : num_(num), den_(1) { };

  int num() const;
  int den() const;

  const Fraction Add(const Fraction& rhs) const;

  //const Fraction operator+(const Fraction& rhs) const;
  const Fraction operator-(const Fraction& rhs) const;

  friend const Fraction operator+(const Fraction& lhs, const Fraction& rhs);
  friend ostream& operator<<(ostream& lhs, const Fraction& rhs);
 private:

  int num_;
  int den_;
};

#endif
