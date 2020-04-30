//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int int64_t
constexpr int mod = 1000'000'007;

int power(int base, int exp, int m) {
    int result = 1;
    while(exp) {
        if(exp & 1) (result *= base) %= m;
        (base *= base) %= m;
        exp >>= 1;
    }
    return result;
}

signed main() {
    int n; cin >> n;
    int a[n]; for(int& i: a) cin >> i;
    int x = a[0], y = a[0];
    for(int i = 1; i < n; ++i) y = __gcd(y, a[i]), x = (x * a[i]) % mod;
    cout << power(x, y, mod);
    return 0;
} //farewell, until we meet again..
