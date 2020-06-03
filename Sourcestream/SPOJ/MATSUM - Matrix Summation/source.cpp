//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define matrix vector<vector<int>>

struct fenwick {
    int n, m;
    matrix bit;
    fenwick(int n, int m) {
        this -> n = n;
        this -> m = m;
        bit.assign(n + 1, vector<int>(m + 1, 0));
    }
    int query(array<int, 2> i) {
        int result = 0;
        for(int x = i[0]; x; x -= x & -x) {
            for(int y = i[1]; y; y -= y & -y) result += bit[x][y];
        }
        return result;
    }
    int query(array<int, 2> lo, array<int, 2> hi) {
        int a = query(hi), b = query({lo[0] - 1, hi[1]});
        int c = query({hi[0], lo[1] - 1}), d = query({lo[0] - 1, lo[1] - 1});
        return a + d - (b + c);
    }
    void update(array<int, 2> i, int delta) {
        for(int x = i[0]; x <= n; x += x & -x) {
            for(int y = i[1]; y <= m; y += y & -y) bit[x][y] += delta;
        }
    }
    bool process();
};

bool fenwick::process() {
    string type; cin >> type;
    int delta;
    array<int, 2> i, lo, hi;
    if(type == "SET") {
        cin >> i[0] >> i[1] >> delta;
        i[0]++, i[1]++;
        update({i}, delta - query({i}, {i}));
        return true;
    } else if(type == "SUM") {
        cin >> lo[0] >> lo[1] >> hi[0] >> hi[1];
        lo[0]++, lo[1]++, hi[0]++, hi[1]++;
        cout << query(lo, hi) << "\n";
        return true;
    } else {
        return false;
    }
}

void hike() {
    int n; cin >> n;
    fenwick tree(n, n);
    while(tree.process());
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
