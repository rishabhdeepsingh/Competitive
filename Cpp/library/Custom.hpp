//
// Created by White Knife on 24/04/20.
//

#include <stack>
#include <deque>
#include <queue>

template <typename T>
class Stack : public std::stack<T> {
  
  T def{};

public:
  Stack() : std::stack<T>() {}
  Stack(T _def) : def(_def), std::stack<T>() {}
  
  T pop() {
    if (std::stack<T>::empty()) {
      return def;
    }
    T tp = std::stack<T>::top();
    std::stack<T>::pop();
    return tp;
  }
};

template <typename T>
class Deque : public std::deque<T> {
  T def{};
public:
  Deque(T _def) : def(_def), std::deque<T>() {}
  Deque() : std::deque<T>() {}
  
  T pop_front() {
    if (std::deque<T>::empty()) {
      return def;
    }
    T tp = std::deque<T>::front();
    std::deque<T>::pop_front();
    return tp;
  }
  
  T pop_back() {
    if (std::deque<T>::empty()) {
      return def;
    }
    T tp = std::deque<T>::back();
    std::deque<T>::pop_back();
    return tp;
  }
};

template <typename T>
class Queue : public std::queue<T> {
  
  T def{};

public:
  Queue() : std::queue<T>() {}
  Queue(T _def) : def(_def), std::queue<T>() {}
  
  T pop() {
    if (std::queue<T>::empty()) {
      return def;
    }
    T tp = std::queue<T>::front();
    std::queue<T>::pop();
    return tp;
  }
};