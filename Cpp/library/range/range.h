#pragma once

#include <algorithm>
#include "../general.hpp"

class NumberIterator : iterator<forward_iterator_tag, int> {
public:
    int v;

    NumberIterator(int _v) : v(_v) {}

    operator int &() { return v; }

    int operator*() { return v; }
};

class range : pii {
public:
    range(int begin, int end) : pii(begin, max(begin, end)) {}

    range(int n) : pii(0, max(0, n)) {}

    NumberIterator begin() {
        return first;
    }

    NumberIterator end() {
        return second;
    }
};
