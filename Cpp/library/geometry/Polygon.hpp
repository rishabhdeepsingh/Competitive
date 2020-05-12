//
// Created by White Knife on 11/05/20.
//

#ifndef CPP_LIBRARY_GEOMETRY_POLYGON_HPP_
#define CPP_LIBRARY_GEOMETRY_POLYGON_HPP_

#pragma once
#include "Segment.hpp"

class Polygon {
  mutable double ar = -1;
  mutable vector<Segment> sid;

public:
  vector<point> vert;
  
  Polygon() {}
  explicit Polygon(const vector<point> &_vert) : vert(_vert) {}
  
  PType area() const {
    if (ar == -1) {
      ar = 0;
      for (size_t i = 0; i < vert.size(); ++i) {
        const point &a = vert[i];
        const point &b = vert[(i + 1) % vert.size()];
        ar += (a.x - b.x) * (a.y + b.y);
      }
      ar = abs(ar) / 2;
    }
    return ar;
  }
  
  bool inside(const point &p, bool strict = false) const {
    bool onSide = false;
    for (const auto &s : sides()) {
      if (s.contains(p)) {
        onSide = true;
        break;
      }
    }
    if (onSide) {
      return !strict;
    }
    double totalAngle = normalize(vert[0], p, vert.back());
    for (int i = 1; i < vert.size(); i++) {
      totalAngle += normalize(vert[i], p, vert[i - 1]);
    }
    return abs(totalAngle) > PI;
  }
  
  const vector<Segment> &sides() const {
    if (sid.size() == 0) {
      sid = vector<Segment>(vert.size());
      for (size_t i = 0; i < vert.size(); ++i) {
        sid[i] = Segment(vert[i], vert[(i + 1) % vert.size()]);
      }
    }
    return sid;
  }
};

#endif //CPP_LIBRARY_GEOMETRY_POLYGON_HPP_
