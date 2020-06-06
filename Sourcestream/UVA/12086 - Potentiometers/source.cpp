//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int int64_t

template<class T, class U> T cast(U x) { 
    T result;
    ostringstream out; out << x;
    istringstream in(out.str()); in >> result; 
    return result; 
}

template<class T> vector<T> split(string s, string separator = " ") {
    vector<T> result;
    for(int i = 0, n = (int)s.length(); i < n; ++i) {
        string a;
        while(i < n and separator.find(s[i]) == string::npos) a += s[i++]; 
            if(!a.empty()) result.emplace_back(cast<T>(a));
        }
    return result;
}

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
    void write(int i, int value) {
        update(i, value - read(i));
    }
};

void hike(int n) {
    vector<int> a(n);
    for(int& i: a) cin >> i;
    fenwick tree(a);
    string query;
    cin.ignore(numeric_limits<int>::max(), '\n');
    while(getline(cin, query)) {
        if(query == "END") break;
        auto q = split<int>(query.substr(1));
        if(query[0] == 'S') tree.write(q[0], q[1]);
        else cout << tree.sum(q[0], q[1]) << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    for(int n, i = 1; cin >> n, n; hike(n)) {
        if(i > 1) cout << "\n";
        cout << "Case " << i++ << ":\n";
    }
    return 0;
} //farewell, until we meet again..
