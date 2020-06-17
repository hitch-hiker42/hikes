//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int int64_t
#define span(a) begin(a), end(a)

bool factor(int num, int den) {
    if(den != 0 and (num % den == 0)) return true;
    return false;
};

int equal(array<int, 3>& x, array<int, 3>& y) {
    array<int, 3> e = {x[0] == y[0], x[1] == y[1], x[2] == y[2]};
    if(e[0] || e[1] || e[2]) {
        if(e[0] and e[1] and e[2]) return 0;
        if((e[0] and e[1]) || (e[1] and e[2]) || (e[0] and e[2])) return 1;
        if(e[0]) {
            array<int, 2> d = {y[1] - x[1], y[2] - x[2]};
            array<int, 2> m; bool test = true;
            if(factor(y[1], x[1])) m[0] = y[1] / x[1]; else test = false;
            if(factor(y[2], x[2])) m[1] = y[2] / x[2]; else test = false;
            test &= (m[0] == m[1]);
            if(d[0] == d[1] || test) return 1;
            return 2;
        } else if(e[1]) {
            array<int, 2> d = {y[0] - x[0], y[2] - x[2]};
            array<int, 2> m; bool test = true;
            if(factor(y[0], x[0])) m[0] = y[0] / x[0]; else test = false;
            if(factor(y[2], x[2])) m[1] = y[2] / x[2]; else test = false;
            test &= (m[0] == m[1]);
            if(d[0] == d[1] || test) return 1;
            return 2;
        } else {
            array<int, 2> d = {y[0] - x[0], y[1] - x[1]};
            array<int, 2> m; bool test = true;
            if(factor(y[0], x[0])) m[0] = y[0] / x[0]; else test = false;
            if(factor(y[1], x[1])) m[1] = y[1] / x[1]; else test = false;
            test &= (m[0] == m[1]);
            if(d[0] == d[1] || test) return 1;
            return 2;
        }
    }
    return -1;
}

int translate(array<int, 3>& x, array<int, 3>& y) {
    array<int, 3> d = {y[0] - x[0], y[1] - x[1], y[2] - x[2]};
    if(d[0] == d[1] and d[1] == d[2]) return 1;
    if(d[0] == d[1] || d[1] == d[2] || d[0] == d[2]) return 2;
    if(d[0] == d[1] + d[2]) return 2;
    if(d[1] == d[0] + d[2]) return 2;
    if(d[2] == d[0] + d[1]) return 2;
    return -1;
}

int scale(array<int, 3>& x, array<int, 3>& y) {
    array<int, 3> m = {factor(y[0], x[0]), factor(y[1], x[1]), factor(y[2], x[2])};
    if(m[0] and m[1] and m[2]) {
        array<int, 3> e = {y[0] / x[0], y[1] / x[1], y[2] / x[2]};
        if(e[0] == e[1] and e[1] == e[2]) return 1;
        if(e[0] * e[1] == e[2]) return 2;
        if(e[1] * e[2] == e[0]) return 2;
        if(e[0] * e[2] == e[1]) return 2;
    }
    if((m[0] and m[1]) and (y[0] / x[0] == y[1] / x[1])) return 2;
    if((m[1] and m[2]) and (y[1] / x[1] == y[2] / x[2])) return 2;
    if((m[0] and m[2]) and (y[0] / x[0] == y[2] / x[2])) return 2;
    return -1;
}

int transcale(array<int, 3>& x, array<int, 3>& y) { //translate + scale
    array<int, 3> d = {y[0] - x[0], y[1] - x[1], y[2] - x[2]};
    array<int, 3> m = {factor(y[0], x[0]), factor(y[1], x[1]), factor(y[2], x[2])};
    if(m[0]) {
        int k = y[0] / x[0];
        if((x[1] + d[2]) * k == y[1]) return 2;
        if((x[2] + d[1]) * k == y[2]) return 2;
        array<int, 2> n = {factor(y[1], k), factor(y[2], k)};
        if(n[0] and n[1]) {
            int r = y[1] / k, s = y[2] / k;
            if((r - x[1]) == (s - x[2])) return 2;
        }
    }
    if(m[1]) {
        int k = y[1] / x[1];
        if((x[0] + d[2]) * k == y[0]) return 2;
        if((x[2] + d[0]) * k == y[2]) return 2;
        array<int, 2> n = {factor(y[0], k), factor(y[2], k)};
        if(n[0] and n[1]) {
            int r = y[0] / k, s = y[2] / k;
            if((r - x[0]) == (s - x[2])) return 2;
        }
    }
    if(m[2]) {
        int k = y[2] / x[2];
        if((x[0] + d[1]) * k == y[0]) return 2;
        if((x[1] + d[0]) * k == y[1]) return 2;
        array<int, 2> n = {factor(y[0], k), factor(y[1], k)};
        if(n[0] and n[1]) {
            int r = y[0] / k, s = y[1] / k;
            if((r - x[0]) == (s - x[1])) return 2;
        }
    }
    array<int, 2> n = {factor(y[1], x[1] + d[0]), factor(y[2], x[2] + d[0])};
    if(n[0] and n[1]) {
        if((y[1] / (x[1] + d[0])) == (y[2] / (x[2] + d[0]))) return 2;
    }
    n[0] = factor(y[0], x[0] + d[1]), n[1] = factor(y[2], x[2] + d[1]);
    if(n[0] and n[1]) {
        if((y[0] / (x[0] + d[1])) == (y[2] / (x[2] + d[1]))) return 2;
    }
    n[0] = factor(y[0], x[0] + d[2]), n[1] = factor(y[1], x[1] + d[2]);
    if(n[0] and n[1]) {
        if((y[0] / (x[0] + d[2])) == (y[1] / (x[1] + d[2]))) return 2;
    }
    array<int, 3> o = {factor(y[0] - y[1], x[0] - x[1]), factor(y[1] - y[2], x[1] - x[2]), factor(y[2] - y[0], x[2] - x[0])};
    if(o[0] and o[1] and o[2]) {
        int i = (y[0] - y[1]) / (x[0] - x[1]);
        int j = (y[1] - y[2]) / (x[1] - x[2]);
        int k = (y[2] - y[0]) / (x[2] - x[0]);
        if(i == j and j == k) return 2;
    }
    return -1;
}

int scalete(array<int, 3>& x, array<int, 3>& y) { //scale + translate
    array<int, 3> d = {y[0] - x[0], y[1] - x[1], y[2] - x[2]};
    array<int, 3> m = {factor(y[0], x[0]), factor(y[1], x[1]), factor(y[2], x[2])};
    if(m[0]) {
        int k = y[0] / x[0];
        if((x[1] * k + d[2]) == y[1]) return 2;
        if((x[2] * k + d[1]) == y[2]) return 2;
        array<int, 2> n = {x[1] * k, x[2] * k};
        if((y[1] - n[0]) == (y[2] - n[1])) return 2;
    }
    if(m[1]) {
        int k = y[1] / x[1];
        if((x[0] * k + d[2]) == y[0]) return 2;
        if((x[2] * k + d[0]) == y[2]) return 2;
        array<int, 2> n = {x[0] * k, x[2] * k};
        if((y[0] - n[0]) == (y[2] - n[1])) return 2;
    }
    if(m[2]) {
        int k = y[2] / x[2];
        if((x[0] * k + d[1]) == y[0]) return 2;
        if((x[1] * k + d[0]) == y[1]) return 2;
        array<int, 2> n = {x[0] * k, x[1] * k};
        if((y[0] - n[0]) == (y[1] - n[1])) return 2;
    }
    array<int, 2> n = {factor(y[1] - d[0], x[1]), factor(y[2] - d[0], x[2])};
    if(n[0] and n[1]) {
        if(((y[1] - d[0]) / x[1]) == ((y[2] - d[0]) / x[2])) return 2;
    }
    n[0] = factor(y[0] - d[1], x[0]), n[1] = factor(y[2] - d[1], x[2]);
    if(n[0] and n[1]) {
        if(((y[0] - d[1]) / x[0]) == ((y[2] - d[1]) / x[2])) return 2;
    }
    n[0] = factor(y[0] - d[2], x[0]), n[1] = factor(y[1] - d[2], x[1]);
    if(n[0] and n[1]) {
        if(((y[0] - d[2]) / x[0]) == ((y[1] - d[2]) / x[1])) return 2;
    }
    array<int, 3> o = {factor(y[0] - y[1], x[0] - x[1]), factor(y[1] - y[2], x[1] - x[2]), factor(y[2] - y[0], x[2] - x[0])};
    if(o[0] and o[1] and o[2]) {
        int i = (y[0] - y[1]) / (x[0] - x[1]);
        int j = (y[1] - y[2]) / (x[1] - x[2]);
        int k = (y[2] - y[0]) / (x[2] - x[0]);
        //cout << i << ' ' << j << ' ' << k << endl;
        if(i == j and j == k) {
            i *= x[0]; j *= x[1]; k *= x[2];
            //cout << y[0] - i << endl;
            if(y[0] - i == y[1] - j and y[1] - j == y[2] - k) return 2;
        }
    }
    return -1;
}

void hike() {
    int p, q, r; cin >> p >> q >> r;
    int a, b, c; cin >> a >> b >> c;
    array<int, 3> src = {p, q, r}, dest = {a, b, c};
    vector<int> v;
    int result = equal(src, dest);
    if(~result) v.push_back(result);
    result = scale(src, dest);
    if(~result) v.push_back(result);
    result = translate(src, dest);
    if(~result) v.push_back(result);
    result = transcale(src, dest);
    if(~result) v.push_back(result);
    result = scalete(src, dest);
    if(~result) v.push_back(result);
    v.push_back(3);
    cout << *min_element(span(v)) << "\n";
}

signed main() {
    int t; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
