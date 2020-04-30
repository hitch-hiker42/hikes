//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int int64_t
constexpr int p = 1000'000'007;
constexpr int q = 1000'000'006;

int power(int base, int exp, int m) {
    int result = 1;
    while(exp) {
        if(exp & 1) result = (result * base) % m;
        base = (base * base) % m;
        exp >>= 1;
    }
    return result;
}

int reduce(string n, int m) {
    int result = 0;
    for(char& d: n) ((result *= 10) += d - '0') %= m;
    return result;
} 

void hike() {
    string n, m; cin >> n >> m;
    int x = reduce(n, p), y = reduce(m, q);
    cout << power(x, y, p) << endl;
}

signed main() {
    int t; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
