#include "IO.hpp"

template<typename T>
struct maxmin_stack {

  void push(const T e) {
    if (s.empty()) {
      mx.push(e);
      mn.push(e);
    } else {
      mx.push(std::max(this->max(), e));
      mn.push(std::min(this->min(), e));
    }
    s.push(e);
  }

  bool empty() {
    return s.empty();
  }

  T top() {
    return s.top();
  }

  void pop() {
    mx.pop();
    mn.pop();
    s.pop();
  }

  T max() {
    if (s.empty()) return numeric_limits<T>::min();
    return mx.top();
  }
  T min() {
    if (s.empty()) return numeric_limits<T>::max();
    return mn.top();
  }
 private:
  stack<T> mx, mn, s;
};