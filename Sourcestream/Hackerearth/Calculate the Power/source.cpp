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

void hike() {
    int x, y; cin >> x >> y;
    cout << power(x, y, mod) << endl;
}

signed main() {
    int t = 1; //cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
