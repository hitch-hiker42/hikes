//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

int main() {
    #define int int64_t
    constexpr int lim = 1000'001;
    bitset<lim> prime; prime.set();
	  prime.reset(0); prime.reset(1);
    for(int i = 4; i < lim; i += 2) prime.reset(i);
    for(int i = 3; i < lim; i += 2) if(prime[i]) {
        for(int j = i * i, k = i << 1; j < lim; j += k) prime.reset(j);
    }
    int n, q; cin >> n >> q;
    int a[n]; for(int& i: a) cin >> i;
    int p[n + 1] = {}; p[1] = prime[a[0]];
    for(int i = 2; i <= n; ++i) p[i] += p[i - 1] + prime[a[i - 1]];
    for(int i = 0; i < q; ++i) {
        int l, r; cin >> l >> r;
        cout << p[r] - p[l - 1] << endl;
    }
    #undef int
    return 0;
} //farewell, until we meet again..
