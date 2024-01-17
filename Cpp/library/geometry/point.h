#pragma once
#include "../IO.hpp"

namespace competitive_cpp {

template<typename T>
struct Point {
  T x{}, y{};

  Point() = default;
  Point(const Point &o) = default;
  Point &operator=(const Point &other) = default;
  explicit Point(T _x) : x(_x) {}
  explicit Point(T _x, T _y) : x(_x), y{_y} {}

  // Addition
  Point<T> operator+(Point<T>) const;
  Point<T> &operator+=(Point<T>);
  // Subtraction
  Point<T> operator-(Point<T>) const;
  Point<T> &operator-=(Point<T>);
  // Negative operator
  Point<T> operator-() const {
    return Point<T>(-this->x, -this->y);
  }

  // Multiplication
  Point<T> operator*(Point<T>) const;
  Point<T> &operator*=(Point<T>);
  template<typename U>
  auto operator*=(U o) -> Point<decltype(x * o)> {
    this->x *= o;
    this->y *= o;
    return *this;
  }
  template<typename U>
  auto operator*(U o) const -> Point<decltype(x * o)> {
    return Point<decltype(x * o)>(this->x * o, this->y * o);
  }

  // Divide
  Point<T> operator/(Point<T>) const;
  Point<T> &operator/=(Point<T>);
  template<typename U>
  auto operator/=(U o) -> Point<decltype(x / o)> {
    this->x /= o;
    this->y /= o;
    return *this;
  }

  // Modulo
  Point<T> operator%(Point<T>) const;
  Point<T> &operator%=(Point<T>);
  template<typename U>
  auto operator%=(U o) -> Point<decltype(x % o)> {
    this->x %= o;
    this->y %= o;
    return *this;
  }

  bool operator==(const Point &rhs) const {
    return this->x == rhs.x and this->y == rhs.y;
  }

  bool operator!=(const Point &rhs) const {
    return !(this->x == rhs.x and this->y == rhs.y);
  }

  T dis(const Point<T>& other) const {
    return hypotl(this->x - other.x, this->y - other.y);
  }
};

template<typename T>
std::istream &operator>>(std::istream &in, competitive_cpp::Point<T> &point) {
  in >> point.x >> point.y;
  return in;
}

// Addition
template<typename T>
Point<T> Point<T>::operator+(Point<T> o) const {
  return Point<T>(this->x + o.x, this->y + o.y);
}
template<typename T>
Point<T> &Point<T>::operator+=(const Point<T> o) {
  this->x += o.x;
  this->y += o.y;
  return *this;
}

// Negation
template<typename T>
Point<T> Point<T>::operator-(Point<T> o) const {
  return Point<T>(this->x - o.x, this->y - o.y);
}
// Subtraction
template<typename T>
Point<T> &Point<T>::operator-=(Point<T> o) {
  this->x -= o.x;
  this->y -= o.y;
  return *this;
}

// Multiplication
template<typename T>
Point<T> &Point<T>::operator*=(const Point<T> o) {
  this->x *= o.x;
  this->y *= o.y;
  return *this;
}
template<typename T>
Point<T> Point<T>::operator*(Point<T> o) const {
  return Point<T>(this->x * o.x, this->y * o.y);
}
template<typename T, typename U>
auto operator*(U o, Point<T> p) -> Point<decltype(p.x * o)> {
  return Point<decltype(p.x * o)>(p.x * o, p.y * o);
}

// Division
template<typename T>
Point<T> Point<T>::operator/(const Point<T> o) const {
  return Point<T>{this->x / o.x, this->y / o.y};
}
template<typename T>
Point<T> &Point<T>::operator/=(const Point<T> o) {
  this->x /= o.x;
  this->y /= o.y;
  return *this;
}

// Modulo
template<typename T>
Point<T> Point<T>::operator%(Point<T> o) const {
  return Point<T>(this->x % o.x, this->y % o.y);
}
template<typename T>
Point<T> &Point<T>::operator%=(Point<T> o) {
  this->x %= o.x;
  this->y %= o.y;
  return *this;
}

// Constants
template<typename T>
static const Point<T> ZERO = Point<T>(0, 0);
template<typename T>
static const Point<T> ONE = Point<T>(T{1}, T{1});
template<typename T>
static const Point<T> TWO = Point<T>(T{2}, T{2});
template<typename T>
static const Point<T> TEN = Point<T>(T{10}, T{10});

} // namespace competitive_cpp
