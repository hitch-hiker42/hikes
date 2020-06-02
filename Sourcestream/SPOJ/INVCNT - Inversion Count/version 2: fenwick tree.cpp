//author: hitch_hiker42;
#include "bits/stdc++.h"
using namespace std;

//solution:
#define span(a) begin(a), end(a)
#define int int64_t

struct fenwick {
    int n, inv = 0;
    vector<int> bit;
    fenwick(int n) {
        this -> n = n + 1;
        bit.assign(n + 1, 0);
    }
    fenwick(vector<int>& a): Fenwick(*max_element(span(a))) {
        for(int i = (int)a.size() - 1; ~i; --i) {
            inv += sum(a[i] - 1);
            update(a[i], 1);
        }
    }
    int sum(int r) {
        int result = 0;
        for(int x = r; x; x -= x & -x) result += bit[x];
        return result;
    }
    int sum(int lo, int hi) {
        return sum(hi) - sum(lo - 1);
    }
    void update(int i, int delta) {
        for(int x = i; x <= n; x += x & -x) bit[x] += delta;
    }
};

void hike() {
    int n; cin >> n;
    vector<int> a(n);
    for(int& i: a) cin >> i;
    fenwick tree(a);
    cout << tree.inv << "\n";
}

signed main() {
    int t; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
