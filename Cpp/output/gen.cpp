#include<bits/stdc++.h>

using namespace std;

int main(){
	int n = 2e5;
	cout << n << ' ';
	for (int i = 0; i < n; ++i) {
		cout << rand() % n + 1 << " ";
	}
	cout << '\n';
	return 0;
}
