#ifndef CPP_LIBRARY_STRING_H_
#define CPP_LIBRARY_STRING_H_

bool is_digit(char x) { return x >= '0' && x <= '9'; }
bool is_upper(char x) { return x >= 'A' && x <= 'Z'; }
bool is_lower(char x) { return x >= 'a' && x <= 'z'; }
bool is_char(char x) { return x == '!' || x == '@' || x == '#' || x == '$' || x == '%' || x == '&'; }

void to_upper(string& s) { transform(all(s), s.begin(), ::toupper); }
void to_lower(string& s) { transform(all(s), s.begin(), ::tolower); }

#endif //CPP_LIBRARY_STRING_H_
