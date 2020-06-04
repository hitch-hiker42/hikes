//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define span(a) begin(a), end(a)
#define int int64_t

struct fenwick {
    int n, m, inv = 0;
    vector<int> bit[2];
    vector<int> left, right;
    fenwick(int n, int m) {
        this -> n = n, this -> m = m;
        bit[0].assign(n + 1, 0);
        bit[1].assign(n + 1, 0);
        left.assign(m + 1, 0);
        right.assign(m + 1, 0);
    }
    fenwick(vector<int>& a): fenwick(*max_element(span(a)), a.size()) {
        for(int i = m, j = 1; i; --i, ++j) {
            left[i] = sum(a[i - 1] - 1, 0);
            right[j] = j - sum(a[j - 1], 1) - 1;
            update(a[i - 1], 1, 0);
            update(a[j - 1], 1, 1);
        }
        for(int k = 1; k <= m; ++k) {
            inv += left[k] * right[k];
        }
    }
    int sum(int i, int key) {
        int result = 0;
        for(int x = i; x; x -= x & -x) result += bit[key][x];
        return result;
    }
    int sum(int lo, int hi, int key) {
        return sum(hi, key) - sum(lo - 1, key);
    }
    void update(int i, int delta, int key) {
        for(int x = i; x <= n; x += x & -x) bit[key][x] += delta;
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
    int t = 1; //cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
