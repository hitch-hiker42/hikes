//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
typedef struct fenwick {
    int n;
    vector<int> bit;
    fenwick(int n) {
        this -> n = n;
        bit.assign(n + 1, 0);
    }
    int sum(int i) {
        int result = 0;
        for(int x = i; x; x -= x & -x) result += bit[x];
        return result;
    }
    int sum(int lo, int hi) {
        return sum(hi) - sum(lo - 1);
    }
    int update(int i, int delta) {
        for(int x = i; x <= n; x += x & -x) bit[x] += delta;
    }
    bool empty() {
        if(sum(n)) return false;
        return true;
    }
    int insert(int i) {
        update(i, 1);
    }
    int erase(int i) {
        update(i, -1);
    }
    int rank(int i) {
        return sum(i);
    }
    int order_statistic(int k) {
        int run = 0, idx = 0;
        for(int i = log2(n); ~i; --i) {
            if(idx + (1 << i) < n and run + bit[idx + (1 << i)] < k) {
                run += bit[idx + (1 << i)];
                idx += (1 << i);
            }
        }
        return idx + 1;
    }
} indexed_multiset;

void hike() {
    int n, q; cin >> n >> q;
    indexed_multiset t(n);
    while(n--) {
        int x; cin >> x;
        t.insert(x);
    }
    while(q--) {
        int x; cin >> x;
        if(x >= 0) t.insert(x);
        if(x < 0) t.erase(t.order_statistic(abs(x)));
    }
    if(t.empty()) cout << 0 << "\n";
    else cout << t.order_statistic(1) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
