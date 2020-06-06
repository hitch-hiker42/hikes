//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
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

int normalize(int x) {
    return (x > 0) - (x < 0);
}

struct fenwick {
    int n;
    vector<int> bit[3];
    fenwick(int n) {
        this -> n = n;
        for(auto& i: bit) i.assign(n + 1, 0);
    }
    fenwick(vector<int>& a): fenwick(a.size()) {
        for(int i = 1, key; i <= n; ++i) {
            key = normalize(a[i - 1]) + 1;
            update(i, 1, key);
        }
    }
    tuple<int, int, int> query(int i) {
        int minus = 0, zero = 0, plus = 0;
        for(int x = i; x; x -= x & -x) minus += bit[0][x];
        for(int x = i; x; x -= x & -x) zero += bit[1][x];
        for(int x = i; x; x -= x & -x) plus += bit[2][x];
        return make_tuple(minus, zero, plus);
    }
    int query(int lo, int hi) {
        auto x = query(hi), y = query(lo - 1);
        int minus = get<0>(x) - get<0>(y);
        int zero = get<1>(x) - get<1>(y);
        int plus = get<2>(x) - get<2>(y);
        if(zero != 0) return 0;
        if(minus & 1) return -1;
        return 1;
    }
    void update(int i, int delta, int key) {
        for(int x = i; x <= n; x += x & -x) bit[key][x] += delta;
    }
    int read(int i) {
        return query(i, i);
    }
    void write(int i, int value) {
        int key = read(i) + 1;
        update(i, -1, key);
        update(i, 1, normalize(value) + 1);
    }
};

signed main() {
    int n, k;
    while(cin >> n, cin >> k) {
        vector<int> a(n);
        for(int& i: a) cin >> i;
        fenwick tree(a);
        cin.ignore(numeric_limits<int>::max(), '\n');
        while(k--) {
            string query; getline(cin, query);
            auto q = split<int>(query.substr(1));
            if(query[0] == 'C') {
                tree.write(q[0], q[1]);
            } else {
                cout << "-0+"[tree.query(q[0], q[1]) + 1];
            }
        }
        cout << "\n";
    }
    return 0;
} //farewell, until we meet again..
