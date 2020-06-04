//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define span(a) begin(a), end(a)
constexpr int lim = 1000'000;
int last[lim];

struct fenwick {
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
    int read(int i) {
        int value = bit[i];
        if(i) {
            int idx = i - (i & -i);
            i = i - 1;
            while(i != idx) {
                value -= bit[i];
                i -= i & -i;
            }
        }
        return value;
    }
    void update(int i, int delta) {
        for(int x = i; x <= n; x += x & -x) bit[x] += delta;
    }
    void set(int i, int value) {
        update(i, value - read(i));
    }
};

struct query {
    int l, r, idx, response;
    query() {};
    query(int l, int r, int idx): l(l), r(r), idx(idx) {}
};

void hike() {
    int n; scanf("%d", &n);
    vector<int> a(n);
    for(int& i: a) scanf("%d", &i);
    fenwick tree(n);
    int q; scanf("%d", &q);
    vector<query> data(q);
    for(int i = 1, l, r; i <= q; ++i) {
        cin >> l >> r;
        data[i - 1] = query(l, r, i);
    }
    memset(last, 0, sizeof last);
    sort(span(data), [](const query& lhs, const query& rhs) {
        if(lhs.r != rhs.r) return lhs.r < rhs.r;
        return lhs.l < rhs.l;
    });
    int idx = 0;
    for(int i = 1; i <= n; ++i) {
        if(last[a[i - 1]]) tree.set(last[a[i - 1]], 0);
        tree.set(i, 1);
        last[a[i - 1]] = i;
        while(idx < q and data[idx].r == i) {
            data[idx].response = tree.sum(data[idx].l, data[idx].r);
            idx = idx + 1;
        }
    }
    sort(span(data), [](const query& lhs, const query& rhs) { 
        return lhs.idx < rhs.idx;
    });
    for(auto& i: data) printf("%d\n", i.response);
}

signed main() {
    int t = 1; //scanf("%d", &t);
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
