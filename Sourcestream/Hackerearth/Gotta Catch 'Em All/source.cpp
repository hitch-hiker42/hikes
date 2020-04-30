//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int int64_t
#define span(a) begin(a), end(a)
constexpr int lim = 1000'001;
int spf[lim];

void sieve() {
    for(int i = 0; i < lim; ++i) spf[i] = (i & 1 ? i : 2);
    for(int i = 3; i < lim; i += 2) if(spf[i] == i) {
        for(int j = i * i, k = i << 1; j < lim; j += k) {
            if(spf[j] == j) spf[j] = i;
        }
    }
}

auto factorize(int n) {
    vector<pair<int, int>> pf;
    while(n != 1) {
        int p = spf[n], k = 0;
        while(spf[n] == p) ++k, n /= p;
        pf.emplace_back(p, k);
    }
    return move(pf);
}

signed main() {
    int t, n; cin >> t >> n;
    sieve();
    auto div = [&](int x) {
        auto pf = factorize(x);
        int result = 1;
        for(auto& j: pf) result *= j.second + 1;
        return result;
    };
    vector<int> v;
    for(int i = 1; i <= n; ++i) v.push_back(div(i));
    sort(span(v));
    for(int i = 0, k; i < t; ++i) {
        cin >> k;
        cout << distance(begin(v), lower_bound(span(v), div(k))) << endl;
    }
    return 0;
} //farewell, until we meet again..
