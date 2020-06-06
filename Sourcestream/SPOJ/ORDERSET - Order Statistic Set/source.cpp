//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define span(a) begin(a), end(a)

struct fenwick {
    int n;
    vector<int> bit;
    fenwick(int n) {
        this -> n = n;
        bit.assign(n + 1, 0);
    }
    int sum(int i) {
        int result = 0;
        while(i) result += bit[i], i -= i & -i;
        return result;
    }
    int sum(int lo, int hi) {
        return sum(hi) - sum(lo - 1);
    }
    void update(int i, int delta) {
        while(i <= n) bit[i] += delta, i += i & -i;
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
    void insert(int i) {
        if(read(i) == 1) return;
        update(i, 1);
    }
    void erase(int i) {
        if(read(i) == 0) return;
        update(i, -1);
    }
    int rank(int i) {
        return sum(i);
    }
    int order_statistic(int k) {
        if(k > sum(n)) return -1;
        int run = 0, idx = 0;
        for(int i = log2(n); ~i; --i) {
            if(idx + (1 << i) < n and run + bit[idx + (1 << i)] < k) {
                run += bit[idx + (1 << i)];
                idx += 1 << i;
            }
        }
        return idx + 1;
    }
};

struct query {
    char type;
    int x;
};


void compress(vector<query>& a, int& m, map<int, int>& hash) {
    int n = a.size();
    vector<int> u, v;
    for(int i = 0; i < n; ++i) if(a[i].type != 'K') u.emplace_back(a[i].x);
    v = u; sort(span(v));
    m = numeric_limits<int>::min();
    for(int i = 0, j = 0; i < n; ++i) {
        if(a[i].type != 'K') {
            a[i].x = distance(begin(v), lower_bound(span(v), u[j])) + 1;
            hash[a[i].x] = u[j];
            m = max(m, a[i].x);
            j = j + 1;
        }
    }
}

void hike() {
    int q, m, k; cin >> q;
    vector<query> data(q);
    for(int i = 0; i < q; ++i) {
        cin >> data[i].type >> data[i].x;
    }
    map<int, int> hash;
    compress(data, m, hash);
    fenwick tree(m);
    for(int i = 0; i < q; ++i) {
        switch(data[i].type) {
            case 'I':
                tree.insert(data[i].x);
                break;
            case 'D':
                tree.erase(data[i].x);
                break;
            case 'K':
                k = tree.order_statistic(data[i].x);
                if(k == -1) cout << "invalid\n";
                else cout << hash[k] << "\n";
                break;
            case 'C':
                cout << tree.rank(data[i].x - 1) << "\n";
                break;
            default: continue;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
