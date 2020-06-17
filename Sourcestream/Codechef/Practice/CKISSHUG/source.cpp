//auhtor: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int int64_t
#define loop(x, start, end) for(int x = start; x < end; ++x)
#define matrix vector<vector<int>>
constexpr int mod = 1000'000'007;

auto identity(int n) {
    matrix id = matrix(n, vector<int>(n));
    loop(i, 0, n) id[i][i] = 1;
    return move(id);
}

auto multiply(matrix& A, matrix& B, int n) {
    matrix C = matrix(n, vector<int>(n));
    loop(i, 0, n) loop(j, 0, n) loop(k, 0, n) (C[i][j] += A[i][k] * B[k][j]) %= mod;
    return move(C);
}

auto power(matrix& base, int exp, int n) {
    matrix result = identity(n);
    while(exp) {
        if(exp & 1) result = multiply(result, base, n);
        base = multiply(base, base, n);
        exp >>= 1;
    }
    return move(result);
}

void hike() {
    int n; cin >> n;
    if(n & 1) {
        matrix T = {{1, 2}, {0, 2}};
        vector<int> F = {2, 2};
        T = power(T, (n - 1) >> 1, 2);
        cout << (T[0][0] * F[0] + T[0][1] * F[1]) % mod << endl;
    } else {
        matrix T = {{1, 1, 1}, {0, 2, 0}, {0, 0, 2}};
        vector<int> F = {1, 1, 2};
        T = power(T, n >> 1, 3);
        cout << (T[0][0] * F[0] + T[0][1] * F[1] + T[0][2] * F[2]) % mod << endl;
    }
}

signed main() {
    int t; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
