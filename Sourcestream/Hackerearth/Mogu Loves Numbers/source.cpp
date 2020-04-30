//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define endl '\n'
#define int int64_t
constexpr int lim = 1000'001;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    bitset<lim> prime; prime.set();
    prime.reset(0); prime.reset(1);
    for(int i = 4; i < lim; i += 2) prime.reset(i);
    for(int i = 3; i < lim; i += 2) if(prime[i]) {
        for(int j = i * i, k = i << 1; j < lim; j += k) prime.reset(j);
    }
    int p[lim + 1] = {};
    for(int i = 2; i < lim; ++i) p[i] = p[i - 1] + prime[i];
    int q; cin >> q;
    for(int i = 0, l, r; i < q; ++i) {
        cin >> l >> r; if(l > r) swap(l, r);
        cout << p[r] - p[l - 1] << endl;
    }
    return 0;
} //farewell, until we meet again..
