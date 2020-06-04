//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int long long int

struct fenwick {
    int n, inv = 0;
    vector<int> bit;
    fenwick(int n) {
        this -> n = n;
        bit.assign(n + 1, 0);
    }
    fenwick(vector<int>& a): fenwick(a.size()) {
        for(int i = n; i; --i) {
            inv += sum(a[i - 1] - 1);
            update(a[i - 1], 1);
        }
    }
    int sum(int i) {
        int result = 0;
        for(int x = i; x; x -= x & -x) result += bit[x];
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
    vector<string> v(n);
    map<string, int> hash;
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        hash[v[i]] = i + 1;
    }
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        string s; cin >> s;
        a[i] = hash[s];
    }
    fenwick tree(a);
    cout << tree.inv << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
