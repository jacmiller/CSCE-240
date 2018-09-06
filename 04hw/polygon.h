#ifndef _240_04HW_POLYGON_H
#define _240_04HW_POLYGON_H

#include <iostream>
using std::ostream;
using std::istream;
#include <cassert>
#include <string>
using std::string;
using std::to_string;
#include "point2d.h"
using csce240::Point2d;
#include "vector2d.h"
using csce240::Vector2d;

namespace csce240 {
struct VertexNode {
    inline VertexNode(const Point2d& vertex, VertexNode* next = nullptr,
      VertexNode* prev = nullptr) :
      vertex_(vertex), next_(next), prev_(prev) {}
    Point2d vertex_;
    VertexNode *next_;
    VertexNode *prev_;
};

class Polygon {
 private:
    int size_;
    VertexNode *vertices_;

    void Add(const Point2d& vertex);
    void ClearVertices();

 public:
    const static unsigned char k_init_success_ = 0;
    const static unsigned char k_init_not_polygon_ = 1;
    const static unsigned char k_init_nonunique_ = 2;
    const static unsigned char k_init_has_collinear_ = 3;

    Polygon() : vertices_(nullptr), size_(0) {}
    Polygon(const Polygon& original);
    ~Polygon();

    int Init(const Point2d* vertices, int count);

    void Offset(Vector2d by);

    void Scale(double units, const Point2d& about);

    inline int size() const { return size_; }
    const string ToString() const;

    Polygon& operator=(const Polygon& original);

    // friend ostream& operator<<(ostream& lhs, const Polygon& rhs);
};

}  // namespace csce240
#endif
