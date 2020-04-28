//author: hitch_hiker42;
#include "bits/stdc++.h"
using namespace std;

//solution;
#define span(a) begin(a), end(a)
#define int int64_t
#define endl '\n'
#define matrix vector<vector<int>>
int mod; //(= 0): static variable;

auto identity(int k) {
    matrix id = matrix(k, vector<int>(k));
    for(int i = 0; i < k; ++i) id[i][i] ^= 1;
    return move(id);
}

auto multiply(matrix& A, matrix& B, int k) {
    matrix C = matrix(k, vector<int>(k));
    for(int i = 0; i < k; ++i) {
        for(int j = 0; j < k; ++j) {
            for(int l = 0; l < k; ++l) (C[i][j] += A[i][l] * B[l][j]) %= mod;
        }
    }
    return move(C);
}

auto power(matrix& base, int exp, int k) {
    matrix result = identity(k);
    while(exp) {
        if(exp & 1) result = multiply(result, base, k);
        base = multiply(base, base, k);
        exp >>= 1;
    }
    return move(result);
}

void hike() {
    int k; cin >> k;
    vector<int> a(k), p(k);
    for(int& i: a) cin >> i;
    matrix T = identity(k + 1);
    rotate(begin(T), prev(end(T)), end(T));
    swap(T[0], T[k]);
    for(int i = 0; i < k; ++i) cin >> T[0][i], T[k][i] = T[0][i];
    int m, n; cin >> m >> n >> mod;
    p[0] = a[0] % mod;
    for(int i = 1; i < k; ++i) (p[i] += p[i - 1] + a[i]) %= mod;
    reverse(span(a)); a.push_back(p[k - 1]);
    matrix X = T, Y = T;
    X = power(X, max((int)0, m - k - 1), k + 1);
    Y = power(Y, max((int)0, n - k), k + 1);
    int x = 0, y = 0;
    if(m != 1) {
        m = m - 1;
        if(m <= k) {
            x = p[m - 1];
        } else {
            for(int i = 0; i < k + 1; ++i) (x += X[k][i] * a[i]) %= mod;
        }
    }
    if(n <= k) {
        y = p[n - 1];
    } else {
        for(int i = 0; i < k + 1; ++i) (y += Y[k][i] * a[i]) %= mod;
    }
    cout << (y - x + mod) % mod << endl; 
}

signed main() {
    int t; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
