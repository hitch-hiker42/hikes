//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int int64_t

int sign(int x) {
    return (x > 0) - (x < 0);
};

auto gcd(int a, int b) {
    if(!b) return make_tuple(a, (int)1, (int)0);
    auto [d, x, y] = gcd(b, a % b);
    return make_tuple(d, y, x - (a / b) * y);
}

bool diophantine(int a, int b, int c, int& x, int& y, int& d) {
    tie(d, x, y) = gcd(abs(a), abs(b));
    if(c % d) return false;
    x = x * sign(a) * (c / d);
    y = y * sign(b) * (c / d);
    return true;
}

auto shift(int a, int b, int x, int y, int k) {
    return make_pair(x + k * b, y - k * a);
}

int adjust(int x, int y, int z) {
    return (x - z) / y;
}

int solve(int a, int b, int c) {
    if(a == 0 and b == 0) {
        if(c) return 0;
        return -1;
    }
    int x, y, d;
    if(!diophantine(a, b, c, x, y, d)) return 0;
    tie(x, y) = shift(a, b, x, y, adjust(x, -b, 0));
    return (x - b);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m, a, k, x;
    while(cin >> n >> m >> a >> k, n || m || a || k) {
        x = solve(m, -a, k + a - n);
        if(!x) {
            cout << "Impossible\n";
            continue;
        }
        if(~x) {
            int result = n + m * x, origin = max(n, k + a);
            int lcm = (m * a) / get<0>(gcd(m, a));
            int k = adjust(result, lcm, origin);
            tie(ignore, result) = shift(lcm, 0, 0, result, k);
            cout << result << "\n";
            continue;
        }
        cout << n << "\n";
    }
    return 0;
} //farewell, until we meet again..
