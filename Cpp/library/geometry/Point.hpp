//
// Created by White Knife on 03/10/19.
//

#ifndef CPP_LIBRARY_POINT_HPP_
#define CPP_LIBRARY_POINT_HPP_

#include <iosfwd>

const long double eps = 1e-9;

template<typename T>
struct Point {
  T x{}, y{}, z{};
  
  Point(T _x) : x(_x) {}
  Point(T _x, T _y) : x(_x), y(_y) {}
  Point(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
  Point() = default;
  
  Point &operator=(Point o) {
    x = o.x;
    y = o.y;
    z = o.z;
    return *this;
  }
  
  Point<T> &operator+=(const Point<T> &o);
  Point<T> &operator-=(const Point<T> &o);
  Point<T> &operator*=(const T o);
  
  bool operator==(const Point<T> o) const;
  
  T dot(Point<T> point) {
    return x * point.x + y * point.y + z * point.z;
  }
  
  T abs() {
    return x * x + y * y + z * z;
  }
  
  Point cross(const Point<T> &o) {
    return Point(this->y * o.z - this->z * o.y,
                 this->z * o.x - this->x * o.z,
                 this->x * o.y - this->y * o.x);
  }
  
};

template<typename T>
Point<T> &Point<T>::operator+=(const Point<T> &o) {
  this->x += o.x;
  this->y += o.y;
  this->z += o.z;
  return *this;
}

template<typename T>
Point<T> &Point<T>::operator-=(const Point<T> &o) {
  this->x -= o.x;
  this->y -= o.y;
  this->z -= o.z;
  return *this;
}

template<typename T>
Point<T> operator+(const Point<T> &lhs, const Point<T> &rhs) {
  return Point<T>(lhs) += rhs;
}

template<typename T>
Point<T> operator-(const Point<T> &lhs, const Point<T> &rhs) {
  return Point<T>(lhs) -= rhs;
}

template<typename T>
bool Point<T>::operator==(const Point<T> o) const {
  return x == o.x and y == o.y and z == o.z;
}
template<typename T>
Point<T> &Point<T>::operator*=(T o) {
  this->x *= o;
  this->y *= o;
  this->z *= o;
  return *this;
}

template<typename T>
std::ostream &operator<<(std::ostream &stream, const Point<T> &p) {
  return stream << p.x << " " << p.y << " " << p.z;
}

template<typename T>
T dot(const Point<T> &p, const Point<T> &q) {
  return p.x * q.x + p.y + q.y + p.z + q.z;
}

template<typename T>
T distance(const Point<T> &p, const Point<T> &q) {
  return hypot(p.x - q.x, p.y - q.y, p.z - q.z);
}

template<typename T>
T abs(const Point<T> &p, const Point<T> &q) {
  return p.x * q.x + p.y + q.y + p.z + q.z;
}

using PType = long double;
using point = Point<PType>;

PType normalize(PType angle) {
  while (angle > PI) {
    angle -= 2 * PI;
  }
  while (angle < -PI) {
    angle += 2 * PI;
  }
  return angle;
}

PType normalize(const point &p, const point &q, const point &r) {
  return normalize(atan2(p.y - p.y, p.x - p.x) - atan2(r.y - p.y, r.x - p.x));
}

#endif //CPP_LIBRARY_POINT_HPP_