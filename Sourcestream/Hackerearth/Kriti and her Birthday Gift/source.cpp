//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int int64_t
#define block(i) i / B
constexpr int N = 100'000, B = 316, p = 31, mod = 1000'000'009;
string a[N]; int ans[N];

struct query {
    string s;
    int lo, hi, idx;
    query() {}
    query(int lo, int hi, int idx): lo(lo), hi(hi), idx(idx) {}
    bool operator < (const query& q) {
        return block(lo) < block(q.lo) || (block(lo) == block(q.lo) and hi < q.hi);
    }
} q[N];

int rollhash(string const& s) {
    int hash = 0, x = 1;
    for(const char& c: s) {
        (hash += (c - 'a' + 1) * x % mod) %= mod;
        x = x * p % mod;
    }
    return hash;
}

struct custom {
    size_t operator () (const string& s) const {
        return rollhash(s);
    }
};

bool equal(const string& s, const string& t) {
    return !(s.compare(t));
}

signed main() {
    int n; cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    int m; cin >> m;
    for(int i = 0; i < m; ++i) {
        cin >> q[i].lo >> q[i].hi >> q[i].s;
        q[i].lo--; q[i].hi--; q[i].idx = i;
    }
    sort(q, q + m);
    unordered_map<string, int, custom> f;
    auto insert = [&](int i, string s) {
        f[a[i]]++;
    };
    auto remove = [&](int i, string s) {
        f[a[i]]--;
    };
    int l = 0, r = -1;
    for(int i = 0; i < m; ++i) {
        int lo = q[i].lo, hi = q[i].hi;
        string s = q[i].s;
        while(lo < l) insert(--l, s);
        while(r < hi) insert(++r, s);
        while(lo > l) remove(l++, s);
        while(r > hi) remove(r--, s);
        ans[q[i].idx] = f[s];
    }
    for(int i = 0; i < m; ++i) cout << ans[i] << "\n";
    return 0;
} //farewell, until we meet again..
