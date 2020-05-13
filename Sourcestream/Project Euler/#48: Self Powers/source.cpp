//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int int64_t
constexpr int MAX = 2000'001;
constexpr int mod[2] = {(int)powl(2, 10), (int)powl(5, 10)};
constexpr int modulo = (int)1e10;
int a[MAX], b[MAX];

int power(int base, int exp, int m) {
    int result = 1;
    while(exp) {
        if(exp & 1) (result *= base) %= m;
        (base *= base) %= m;
        exp >>= 1;
    }
    return result;
}

void precompute() {
    a[0] = b[0] = -1; //undefined;
    for(int i = 1; i < MAX; ++i) {
        a[i] = power(i, i, mod[0]);
        b[i] = power(i, i, mod[1]);
    }
}

auto gcd(int a, int b) {
    if(!b) return make_tuple(a, (int)1, (int)0);
    int d, x, y; tie(d, x, y) = gcd(b, a % b);
    return make_tuple(d, y, x - (a / b) * y);
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
    int n, x = 0, y = 0; cin >> n;
    for(int i = 1; i <= n; ++i) {
        (x += a[i]) %= mod[0];
        (y += b[i]) %= mod[1];
    }
    vector<pair<int, int>> a = {{x, mod[0]}, {y, mod[1]}};
    int sum = crt(a, modulo);
    cout << sum << endl;
}

signed main() {
    precompute();
    int t = 1; //cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
