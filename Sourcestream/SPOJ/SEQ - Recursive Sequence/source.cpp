//author: hitch_hiker42;
#include "bits/stdc++.h"
using namespace std;

//solution:
#define endl '\n'
#define int int64_t
#define span(a) begin(a), end(a)
#define matrix vector<vector<int>>
constexpr int mod = 1000'000'000;

auto identity(int k) {
    matrix id = matrix(k, vector<int>(k));
    for(int i = 0; i < k; ++i) id[i][i] = 1;
    return move(id);
}

auto multiply(matrix& A, matrix& B, int k) {
    matrix C = matrix(k, vector<int>(k));
    for(int i = 0; i < k; ++i) {
        for(int j = 0; j < k; ++j) {
            for(int l = 0; l < k; ++l) {
                (C[i][j] += A[i][l] * B[l][j]) %= mod;
            }
        }
    }
    return move(C);
}

auto power(matrix& base, int exp, int k) {
    matrix result = identity(k);
    while(exp) {
        if(exp & 1) result = multiply(base, result, k);
        base = multiply(base, base, k);
        exp >>= 1;
    }
    return result;
}

void hike() {
    int k; cin >> k;
    vector<int> b(k), c(k);
    for(int& i: b) cin >> i;
    for(int& i: c) cin >> i;
    int n; cin >> n;
    reverse(span(b));
    matrix T = identity(k);
    rotate(begin(T), prev(end(T)), end(T));
    for(int i = 0; i < k; ++i) T[0][i] = c[i];
    T = power(T, max(0LL, n - k), k);
    if(n <= k) swap(T[0], T[n - 1]);
    int term = 0;
    for(int i = 0; i < k; ++i) (term += T[0][i] * b[i]) %= mod;
    cout << term << endl;
}

signed main() {
    int t; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
