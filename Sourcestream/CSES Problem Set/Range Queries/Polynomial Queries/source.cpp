//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int int64_t

struct fenwick {
    int n;
    vector<int> bit[6];
    fenwick(int n) {
        this -> n = n;
        bit[0].assign(n + 1, 0);
        bit[1].assign(n + 1, 0);
        bit[2].assign(n + 1, 0);
        bit[3].assign(n + 1, 0);
        bit[4].assign(n + 1, 0);
        bit[5].assign(n + 1, 0);
    }
    fenwick(vector<int>& a): fenwick(a.size()) {
        for(int i = 1; i <= n; ++i) updatex(i, a[i - 1], 5);
    }
    int queryx(int i, int key) {
        int result = 0;
        for(int x = i; x; x -= x & -x) result += bit[key][x];
        return result;
    }
    int query(int i) {
        int a = queryx(i, 0), b = queryx(i, 1), c = queryx(i, 2);
        int d = queryx(i, 3), e = queryx(i, 4), f = queryx(i, 5);
        return a * i + b + ((c * i * i + d * i + e) / 2) + f;
    }
    int query(int lo, int hi) {
        return query(hi) - query(lo - 1);
    }
    void updatex(int i, int delta, int key) {
        for(int x = i; x <= n; x += x & -x) bit[key][x] += delta;
    }
    void updater(int lo, int hi, int delta, int key) {
        updatex(lo, delta, key);
        updatex(hi + 1, -delta, key);
    }
    void update(int lo, int hi, int delta) {
        updater(lo, hi, delta, 0);
        updater(lo, hi, -(lo - 1) * delta, 1);
        updater(hi + 1, n, (hi - lo + 1) * delta, 1);
        updater(lo, hi, 1, 2);
        updater(lo, hi, -(2 * lo - 1), 3);
        updater(lo, hi, lo * lo - lo, 4);
        updater(hi + 1, n, (hi - lo) * (hi - lo + 1), 4);
    }
};

signed main() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int& i: a) cin >> i;
    fenwick tree(a);
    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            int a, b; cin >> a >> b;
            tree.update(a, b, 1);
        } else {
            int a, b; cin >> a >> b;
            cout << tree.query(a, b) << "\n";
        }
    }
    return 0;
} //farewell, until we meet again..
