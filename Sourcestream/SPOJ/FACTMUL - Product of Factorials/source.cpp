//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int int64_t
constexpr int mod = 109546051211;

auto factorize(int n) {
    map<int, int> factorization;
    for(int i = 2; i <= n / i; ++i) {
        while(n % i == 0) factorization[i]++, n /= i;
    }
    if(n > 1) factorization[n] = 1;
    return move(factorization);
}

auto gcd(int a, int b) {
    if(b == 0) return make_tuple(a, (int)1, (int)0);
    int x, y, d; tie(d, x, y) = gcd(b, a % b);
    return make_tuple(d, y, x - y * (a / b));
}

int crt(const vector<pair<int, int>>& a, int n) {
    int result = 0;
    for(auto& i: a) {
        int r = i.first, m = i.second, k = n / m;
        int x = get<1>(gcd(k, m));
        result += ((x * k) % n * r) % n;
    }
    return (result + n) % n;
}

void hike() {
    int n; cin >> n;
    auto pf = factorize(mod);
    vector<pair<int, int>> a;
    for(auto& i: pf) {
        int p = i.first, k = i.second;
        int m = powl(p, k), x = 1, r = 1;
        for(int j = 1; j <= n; ++j) {
            (x *= j) %= m;
            (r *= x) %= m;
        }
        a.push_back({r, m});
    }
    cout << crt(a, mod) << endl;
}

signed main() {
    int t = 1; //cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
