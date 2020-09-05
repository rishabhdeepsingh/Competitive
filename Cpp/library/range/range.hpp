#pragma once

#include "../IO.hpp"

class NumberIterator : iterator<forward_iterator_tag, int> {
public:
    int v;

    NumberIterator(int _v) : v(_v) {}

    operator int &() { return v; }

    int operator*() { return v; }
};

class range : pair<int,int> {
public:
    range(int begin, int end) : pair<int,int>(begin, max(begin, end)) {}

    range(int n) : pair<int,int>(0, max(0, n)) {}

    NumberIterator begin() {
        return first;
    }

    NumberIterator end() {
        return second;
    }
};
