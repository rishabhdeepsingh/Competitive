#include <bits/stdc++.h>
using namespace std;
using ll = long long;
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

// Returns Pure random no seed required
template<class T> T Rand(){ uniform_int_distribution<T> dist; return (T) dist(rnd); }
template<class T, T Min, T Max> T Rand(){ return Min + Rand<T>() % (Max - Min - 1); }

int rand(int s, int e) {
    return s + rand() % (e - s + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    int tc = Rand<int, 1, 10>();
    
    cout << tc << endl;
}
