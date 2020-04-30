//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int int64_t
constexpr int mod = 1000'000'007;

signed main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n, --n, n %= mod;
        cout << (2 * n * n + 3 * n + 1) % mod << endl;
    }
} //farewell, until we meet again..
