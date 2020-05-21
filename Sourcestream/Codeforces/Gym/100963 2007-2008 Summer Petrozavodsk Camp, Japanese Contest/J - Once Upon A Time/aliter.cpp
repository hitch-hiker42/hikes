//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int int64_t

auto gcd(int a, int b) {
    if(!b) return make_tuple(a, (int)1, (int)0);
    int d, x, y; tie(d, x, y) = gcd(b, a % b);
    return make_tuple(d, y, x - (a / b) * y);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m, a, k;
    while(cin >> n >> m >> a >> k, n || m || a || k) {
        int d, x, y; tie(d, x, y) = gcd(m, a);
        if((k + a - n) % d) {
            cout << "Impossible\n"; 
            continue;
        }
        (x *= (k + a - n) / d) %= (a / d);
        while(m * x < (k + a - n) || x < 0) x += a / d;
        cout << n + m * x << "\n";
    }
    return 0;
} //farewell, until we meet again..
