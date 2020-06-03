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
        for(int i = 1; i <= n; ++i) update(i, a[i - 1]);
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
    char type; scanf(" %c", &type);
    int lo, hi, i, x;
    switch(type) {
      case 'u':
          scanf("%lld %lld", &i, &x);
          update(i, x);
          break;
      case 'q':
          scanf("%lld %lld", &lo, &hi);
          printf("%lld\n", query(lo, hi));
          break;
      default: return;
    }
}

void hike() {
    int n; scanf("%lld", &n);
    vector<int> a(n);
    for(int& i: a) scanf("%lld", &i);
    fenwick tree(a);
    int q; scanf("%lld", &q);
    while(q--) tree.process();
}

signed main() {
    int t = 1; //scanf("%lld", &t);
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
