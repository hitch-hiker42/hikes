//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;
 
//solution:
#define int int64_t
#define matrix vector<vector<int>>
constexpr int mod = 1000'000'007;
 
auto identity(int n) {
    matrix id = matrix(n, vector<int>(n));
    for(int i = 0; i < n; ++i) id[i][i] ^= 1;
    return move(id);
}
 
auto multiply(matrix& A, matrix& B, int n) {
    matrix C = matrix(n, vector<int>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < n; ++k) {
                (C[i][j] += A[i][k] * B[k][j]) %= mod;
            }
        }
    }
    return move(C);
}
  
auto power(matrix& base, int k, int n) {
    matrix result = identity(n);
    while(k) {
        if(k & 1) result = multiply(result, base, n);
        base = multiply(base, base, n);
        k >>= 1;
    }
    return move(result);
}
 
signed main() {
    int n, k; cin >> n >> k;
    matrix a(n, vector<int>(n));
    for(auto& i: a) for(int& j: i) cin >> j;
    a = power(a, k, n);
    int count = 0;
    for(auto& i: a) for(int& j: i) (count += j) %= mod;
    cout << count << endl;
    return 0;
} //farewell, until we meet again..
