#pragma once

#include "Line.hpp"

const ld eps = 1e-9;

class Segment {
  mutable Line l;
public:
  point a, b;
  
  Segment() {}
  Segment(const point &_a, const point &_b) : a(_a), b(_b) {}
  
  bool contains(const point &p) const {
    return distance(line(), p) < eps &&
        p.x > std::min(a.x, b.x) - eps &&
        p.x < std::max(a.x, b.x) + eps &&
        p.y > std::min(a.y, b.y) - eps &&
        p.y < std::max(a.y, b.y) + eps;
  }
  
  const Line &line() const {
    if (l.a == 0 && l.b == 0) {
      l = ::line(a, b);
    }
    return l;
  }
  
  PType length() const {
    return distance(a, b);
  }
};
