#ifndef CPP_LIBRARY_STRING_H_
#define CPP_LIBRARY_STRING_H_
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using std::string;
using std::vector;

bool is_digit(char x) { return x >= '0' && x <= '9'; }
bool is_upper(char x) { return x >= 'A' && x <= 'Z'; }
bool is_lower(char x) { return x >= 'a' && x <= 'z'; }
bool is_char(char x) { return x == '!' || x == '@' || x == '#' || x == '$' || x == '%' || x == '&'; }

void to_upper(string &s) { transform(s.begin(), s.end(), s.begin(), ::toupper); }
void to_lower(string &s) { transform(s.begin(), s.end(), s.begin(), ::tolower); }

vector<string> split(string s, const string &delimiter) {
  vector<string> res;
  size_t pos = 0;
  std::string token;
  while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
    res.push_back(token);
    s.erase(0, pos + delimiter.length());
  }
  res.push_back(s);
  return res;
}

#endif //CPP_LIBRARY_STRING_H_
