#include "polygon.h"
using csce240::Polygon;

namespace csce240 {
  Polygon::Polygon(const Polygon& original) {
    vertices_ = nullptr;
    size_ = 0;

    if (original.vertices_ != nullptr)
      Add(original.vertices_->vertex_);

    for (VertexNode *curr = original.vertices_->next_;
      curr != original.vertices_;
      curr = curr->next_)
      Add(curr->vertex_);
  }

  Polygon::~Polygon() {
    ClearVertices();
  }

  bool HasCollinearVertices(const Point2d* vertices, int size) {
    for (int i = 2; i < size; i++)
      if (Point2d::Collinear(vertices[i - 2], vertices[i - 1], vertices[i]))
        return true;
    if (Point2d::Collinear(vertices[size - 2], vertices[size - 1], vertices[0]))
      return true;
    if (Point2d::Collinear(vertices[size - 1], vertices[0], vertices[1]))
      return true;
    return false;
  }

  bool HasNonUnique(const Point2d* vertices, int size) {
    for (int i = 0; i < size; ++i)
      for (int j = 0; j < size; j++)
        if (i != j && vertices[i] == vertices[j])
          return true;
    return false;
  }

  int Polygon::Init(const Point2d* vertices, int count) {
    if (count < 3)
      return Polygon::k_init_not_polygon_;

    if (HasNonUnique(vertices, count))
      return Polygon::k_init_nonunique_;

    if (vertices_ != nullptr)
      ClearVertices();

    if (HasCollinearVertices(vertices, count))
      return Polygon::k_init_has_collinear_;

    for (int i = 0; i < count; ++i)
      Add(vertices[i]);
    return Polygon::k_init_success_;
  }

  void Polygon::Offset(Vector2d by) {
    vertices_->vertex_ = vertices_->vertex_ + by;
    for (VertexNode *curr = vertices_->next_;
      curr != vertices_;
      curr = curr->next_)
      curr->vertex_ = curr->vertex_ + by;
  }

  void Polygon::Scale(double units, const Point2d& about) {
    vertices_->vertex_ = vertices_->vertex_
      + units*(vertices_->vertex_ - about).GetUnit();
    for (VertexNode *curr = vertices_->next_;
      curr != vertices_;
      curr = curr->next_)
      curr->vertex_ = curr->vertex_ + units*(curr->vertex_ - about).GetUnit();
  }

  void Polygon::Add(const Point2d& vertex) {
    if (vertices_ != nullptr) {
      if (vertices_->next_ != nullptr) {
        vertices_->prev_->next_ =
          new VertexNode(vertex, vertices_, vertices_->prev_);

        vertices_->prev_ = vertices_->prev_->next_;
      }
      else {
        vertices_->next_ = vertices_->prev_
          = new VertexNode(vertex, vertices_, vertices_);
      }
    }
    else {
      vertices_ = new VertexNode(vertex);
    }
    ++size_;
  }

  Polygon &Polygon::operator=(const Polygon& original) {
    if (this == &original)
      return *this;

    this->ClearVertices();

    if (original.vertices_ == nullptr)
      return *this;

    this->Add(original.vertices_->vertex_);
    for (VertexNode * curr = original.vertices_->next_;
      curr != original.vertices_;
      curr = curr->next_)
      this->Add(curr->vertex_);
    return *this;
  }
  const string Polygon::ToString() const {
    if (vertices_ == nullptr)
      return "";

    string concat = ">";
    VertexNode *curr = vertices_;
    for (int i = 0; i < size_; ++i) {
      concat += curr->vertex_.ToString();

      if (i < size_ - 1)
        concat += "->";

      curr = curr->next_;
    }
    concat += "-";

    return concat;
  }

  void Polygon::ClearVertices() {
    if (vertices_ == nullptr)
      return;

    VertexNode *tmp, *curr(vertices_->next_);
    while (curr != vertices_) {
      tmp = curr;
      curr = curr->next_;

      delete tmp;
    }

    vertices_ = nullptr;
    size_ = 0;
  }

  ostream& operator<< (ostream& lhs, const Polygon& rhs) {
  if (rhs.vertices_ == nullptr)
  return lhs;

  lhs << ">" << rhs.vertices_->vertex_;

  for (VertexNode *curr = rhs.vertices_->next_;
  curr != rhs.vertices_;
  curr = curr->next_)
  lhs << "->" << curr->vertex_;

  lhs << "-";

  return lhs;
  }
}  // namespace csce240
