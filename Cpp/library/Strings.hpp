#pragma once
#include "IO.hpp"

static bool is_digit(char x) { return x >= '0' && x <= '9'; }
static bool is_upper(char x) { return x >= 'A' && x <= 'Z'; }
static bool is_lower(char x) { return x >= 'a' && x <= 'z'; }
static bool is_vowel(char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; }
static bool is_special_char(char x) {
  return x == '!' || x == '@' || x == '#' || x == '$' || x == '%' || x == '&';
}

static void to_upper(string &s) {
  transform(s.begin(),
            s.end(),
            s.begin(),
            ::toupper);
}
static void to_lower(string &s) {
  transform(s.begin(),
            s.end(),
            s.begin(),
            ::tolower);
}

/**
 * @param str input string to compress into chars and number.
 * @return pair<char,int> which is a compressed sequence.
 */
vector<pair<char, int>> compress(const std::string &str) {
  int len = str.length();
  vector<pair<char, int>> res;
  for (int i = 0; i < len; ++i) {
    if (res.empty() || res.back().first != str[i]) {
      res.emplace_back(str[i], 1);
    }
    if (res.back().first == str[i]) {
      res.back().second++;
    }
  }
  return res;
}
template<typename Out>
static void split(const std::string &s, char delim, Out result) {
  std::stringstream ss(s);
  std::string item;
  while (std::getline(ss, item, delim)) {
    *(result++) = item;
  }
}

/*
 * Note that this solution does not skip empty tokens, so the following
 * will find 4 items, one of which is empty:
 * std::vector<std::string> x = split("one:two::three", ':');
 */
static std::vector<std::string> split(const std::string &s, char delim) {
  std::vector<std::string> elems;
  split(s, delim, std::back_inserter(elems));
  return elems;
}