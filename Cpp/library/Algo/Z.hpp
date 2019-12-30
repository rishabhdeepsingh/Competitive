#ifndef CPP_LIBRARY_ALGO_Z_HPP_
#define CPP_LIBRARY_ALGO_Z_HPP_

#include <vector>
#include <string>

/*
 * Linear time pattern matching function
 */
std::vector<int> ZTransform(std::string s) {
    int n = (int) s.length();
    std::vector<int> z(n);
    for(int i = 1, l = 0, r = 0; i < n; ++i){
        if(i <= r)
            z[i] = std::min(r - i + 1, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if(i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
#endif //CPP_LIBRARY_ALGO_Z_HPP_
