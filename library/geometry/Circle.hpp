#pragma once
#include "Line.hpp"

class Circle {
 public:
  point center;
  PType r;

  Circle(const point &center, const PType _r) : center(center), r(_r) {}
};

vector<point> intersect(const Circle &c, const Line &l) {
  PType dist = distance(l, c.center);
  if (dist > c.r + eps) {
    return vector<point>(0);
  }
  auto perp = perpendicular(l, c.center);
  auto base = intersect(l, perp);
  if (dist > c.r - eps) {
    return vector<point>(1, base);
  }
  PType delta = sqrt(c.r * c.r - dist * dist);
  vector<point> result;
  result.reserve(2);
  result.push_back(point(base.x + perp.a * delta, base.y + perp.b * delta));
  result.push_back(point(base.x - perp.a * delta, base.y - perp.b * delta));
  return result;
}

vector<point> intersect(const Circle &c, const Circle &d) {
  PType dist = distance(c.center, d.center);
  if (dist < eps) {
    return vector<point>(0);
  }
  PType a = 2 * (d.center.x - c.center.x);
  PType b = 2 * (d.center.y - c.center.y);
  PType f =
      d.r * d.r - c.r * c.r + c.center.x * c.center.x - d.center.x * d.center.x
          + c.center.y * c.center.y - d.center.y * d.center.y;
  auto l = getLine(a, b, f);
  return intersect(c, l);
}

vector<point> touchingpoints(const Circle &c, const point &p) {
  PType dist = distance(c.center, p);
  if (dist < c.r - eps) {
    return vector<point>(0);
  }
  if (dist < c.r + eps) {
    return vector<point>(1, p);
  }
  Circle power(p, sqrt((dist - c.r) * (dist + c.r)));
  return intersect(c, power);
}
