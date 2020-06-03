//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int long long int

struct fenwick {
    int n;
    vector<int> bit;
    fenwick(int n) {
        this -> n = n;
        bit.assign(n + 1, 0);
    }
    fenwick(vector<int>& a): fenwick(a.size()) {
        for(int i = 1; i <= n; ++i) update(i, a[i -1]);
    }
    int query(int i) {
        int result = 0;
        for(int x = i; x; x -= x & -x) result += bit[x];
        return result;
    }
    int query(int lo, int hi) {
        return query(hi) - query(lo - 1);
    }
    void update(int i, int delta) {
        for(int x = i; x <= n; x += x & -x) bit[x] += delta;
    }
    void process();
};

void fenwick::process() {
    int type, i, j, v; cin >> type;
    switch(type) {
        case 1: 
            scanf("%lld", &i); ++i;
            v = query(i, i);
            printf("%lld\n", v);
            update(i, -v);
            break;
        case 2: 
            scanf("%lld %lld", &i, &v); ++i;
            update(i, v);
            break;
        case 3: 
            scanf("%lld %lld", &i, &j); ++i, ++j;
            printf("%lld\n", query(i, j));
            break;
        default: return;
    }
}

void hike() {
    int n, q; scanf("%lld %lld", &n, &q);
    vector<int> v(n);
    for(int& i: v) scanf("%lld", &i);
    fenwick tree(v);
    while(q--) tree.process();
}

signed main() {
    int t; cin >> t;
    for(int i = 1; i <= t; printf("Case %lld:\n", i++), hike());
    return 0;
} //farewell, until we meet again..
