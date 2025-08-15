#include<bits/stdc++.h>

using namespace std;

int main() {
  cout << 1 << '\n';
  int n = 1e5;
  cout << n << '\n';
  for (int i = 0; i < n; ++i) {
    cout << rand() % n + 1 << " ";
  }
  cout << '\n';
  return 0;
}
