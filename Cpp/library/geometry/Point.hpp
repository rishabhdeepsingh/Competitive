//
// Created by White Knife on 03/10/19.
//
#pragma once

#include "../IO.hpp"

template <typename T>
struct Point {
  T x{}, y{}, z{};
  
  Point() = default;
  Point(T _x) : x(_x) {}
  Point(T _x, T _y) : x(_x), y(_y) {}
  Point(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
  
  Point& operator=(Point o) {
    x = o.x;
    y = o.y;
    z = o.z;
    return *this;
  }
  
  Point<T>& operator+=(const Point<T>& o);
  Point<T>& operator-=(const Point<T>& o);
  Point<T>& operator*=(const T o);
  Point<T>& operator*=(const Point<T>& o);
  Point<T>& operator/=(const Point<T>& o);
  Point<T>& operator%=(const Point<T>& o);
  Point<T>& operator%=(T o);
  
  bool operator==(const Point<T>& o) const;
  bool operator!=(const Point<T>& o) const;
  
  T dot(Point<T> point) {
    return x * point.x + y * point.y + z * point.z;
  }
  
  Point<T> cross(const Point<T>& o) {
    return Point(
        this->y * o.z - this->z * o.y,
        this->z * o.x - this->x * o.z,
        this->x * o.y - this->y * o.x
    );
  }
  
  void abs() {
    this->x = std::abs(thi->x);
    this->y = std::abs(thi->y);
    this->z = std::abs(thi->z);
  }
  
  static const Point<T> ZERO;
  static const Point<T> ONE;
  static const Point<T> TEN;
  
  void swap12() { swap(x, y); }
  void swap21() { swap12(); }
  void swap23() { swap(y, z); }
  void swap32() { swap23(); }
  void swap13() { swap(x, z); }
  void swap31() { swap13(); }
};

template <typename T> Point<T> const Point<T>::ZERO{0, 0, 0};
template <typename T> Point<T> const Point<T>::ONE{1, 1, 1};
template <typename T> Point<T> const Point<T>::TEN{10, 10, 10};

template <typename T>
bool Point<T>::operator==(const Point<T>& o) const { return x == o.x and y == o.y and z == o.z; }

template <typename T>
bool Point<T>::operator!=(const Point<T>& o) const { return !(*this == o); }

template <typename T>
Point<T>& Point<T>::operator+=(const Point<T>& o) {
  this->x += o.x;
  this->y += o.y;
  this->z += o.z;
  return *this;
}

template <typename T>
Point<T> operator+(const Point<T>& lhs, const Point<T>& rhs) { return Point<T>(lhs) += rhs; }
template <typename T>
Point<T> operator+(const Point<T>& lhs, T& rhs) { return Point<T>(lhs) += rhs; }

template <typename T>
Point<T>& Point<T>::operator-=(const Point<T>& o) {
  this->x -= o.x;
  this->y -= o.y;
  this->z -= o.z;
  return *this;
}

template <typename T>
Point<T> operator-(const Point<T>& lhs, const Point<T>& rhs) { return Point<T>(lhs) -= rhs; }

template <typename T>
Point<T>& Point<T>::operator*=(T o) {
  this->x *= o;
  this->y *= o;
  this->z *= o;
  return *this;
}

template <typename T>
Point<T>& Point<T>::operator*=(const Point<T>& o) {
  this->x *= o.x;
  this->y *= o.y;
  this->z *= o.z;
  return *this;
}

template <typename T>
Point<T> operator*(const Point<T>& lhs, const Point<T>& rhs) { return Point<T>(lhs) *= rhs; }

template <typename T>
Point<T>& Point<T>::operator/=(const Point<T>& o) {
  if (o.x != 0) { this->x /= o.x; }
  if (o.y != 0) { this->y /= o.y; }
  if (o.z != 0) { this->z /= o.z; }
  return *this;
}

template <typename T>
Point<T> operator/(const Point<T>& lhs, const Point<T>& rhs) { return Point<T>(lhs) /= rhs; }

template <typename T>
Point<T>& Point<T>::operator%=(const T o) {
  this->x %= o;
  this->y %= o;
  this->z %= o;
  return *this;
}

template <typename T>
Point<T>& Point<T>::operator%=(const Point<T>& o) {
  this->x %= o.x;
  this->y %= o.y;
  this->z %= o.z;
  return *this;
}

template <typename T>
Point<T> operator%(const Point<T>& lhs, const Point<T>& rhs) { return Point<T>(lhs) %= rhs; }

template <typename T>
T dot(const Point<T>& p, const Point<T>& q) {
  return p.x * q.x + p.y + q.y + p.z + q.z;
}

template <typename T>
T distance(const Point<T>& p, const Point<T>& q) {
  return hypot(p.x - q.x, p.y - q.y, p.z - q.z);
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Point<T>& p) {
  return stream << p.x << " " << p.y << " " << p.z;
}

template <typename T>
std::istream& operator>>(std::istream& in, Point<T>& point) {
  in >> point.x >> point.y >> point.z;
  return in;
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

PType normalize(const point& p, const point& q, const point& r) {
  return normalize(atan2(PType(p.y - p.y), PType(p.x - p.x)) - atan2(PType(r.y - p.y), PType(r.x - p.x)));
}
