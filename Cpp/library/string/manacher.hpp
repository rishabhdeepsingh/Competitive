#pragma once
#include "../IO.hpp"

class Manacher {
  string s;
  string init(string s) {
    string res = "#";
    for (char c : s) {
      res += c;
      res += '#';
    }
    return res;
  }

public:
  explicit Manacher(string _s) : s(move(_s)) {
    s = init(s);
  }
  
  string manacher(string s) {
    s = init(s);
    int len = s.size();
    vector<int> p(len, 0);
    /*
        pos: Record the current center position of the longest palindrome
        maxR: Record the rightmost position that the current longest palindrome can reach
        longest: Record the current number of longest palindromes
        ans: Record the center position of the final longest palindrome
    */
    int pos = 0, ans = 0, longest = 0, maxR = 0;
    p[0] = 1;
    for (int i = 0; i < len; ++i) {
      if (i < maxR)
        p[i] = min(p[2 * pos - i], (maxR - i));
      else
        p[i] = 1;
      while ((i - p[i] >= 0) && (i + p[i] < len) && (s[i - p[i]] == s[i + p[i]])) {
        p[i]++;
      }
      if (i + p[i] - 1 > maxR) {
        maxR = i + p[i] - 1;
        pos = i;
      }
      if (p[i] > longest) {
        longest = p[i];
        ans = i;
      }
    }
    longest--;
    string res;
    for (int k = 0; k < longest; k++) {
      res += s[ans - longest + 2 * k + 1];
    }
    return res;
  }
};