#pragma once

#include "Point3.hpp"

class Line {
public:
  PType a;
  PType b;
  PType c;
  
  Line() : Line(0, 0, 0) {}
  Line(const PType a, const PType b, const PType c) : a(a), b(b), c(c) {}
};

Line getLine(PType a, PType b, PType c) {
  PType g = hypot(a, b);
  return Line(a / g, b / g, c / g);
}

Line line(const point &p, const point &q) {
  PType a = p.y - q.y;
  PType b = q.x - p.x;
  PType c = -a * p.x - b * p.y;
  return getLine(a, b, c);
}

PType distance(const Line &l, const point &p) {
  return abs(l.a * p.x + l.b * p.y + l.c);
}

Line perpendicular(const Line &l, const point &p) {
  return Line(-l.b, l.a, p.x * l.b - p.y * l.a);
}

point intersect(const Line &a, const Line &b) {
  PType det = a.b * b.a - a.a * b.b;
  return point((a.c * b.b - a.b * b.c) / det, (a.a * b.c - a.c * b.a) / det);
}
