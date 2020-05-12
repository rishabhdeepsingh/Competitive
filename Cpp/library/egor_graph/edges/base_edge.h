#pragma once

#include "../../general.hpp"

class BaseEdge {
public:
  const int from;
  const int to;
  int id;
  
  BaseEdge(int _from, int _to) : from(_from), to(_to) {}
  
  BaseEdge *transposed() { return nullptr; }
  BaseEdge *reverse() { return nullptr; }
};

