//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int int64_t
#define matrix vector<vector<int>>
#define loop(x, start, end) for(int x = start; x < end; ++x)
constexpr int mod = 98'765'431;

auto identity(int n) {
    matrix id(n, vector<int>(n));
    loop(i, 0, n) id[i][i] ^= 1;
    return move(id);
}

auto multiply(matrix& A, matrix& B, int n) {
    matrix C(n, vector<int>(n));
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
    int n, k, x, y; cin >> n >> k;
    int F[] = {0, 1};
    int a[n], b[n] = {};
    loop(i, 0, n) cin >> a[i];
    if(n == 1) {
        cout << 0 << endl;
	return;
    }
    matrix M = {{0, n - 1}, {1, n - 2}};
    M = power(M, k - 1, 2);
    x = ((M[0][0] * F[0]) % mod + (M[0][1] * F[1]) % mod) % mod;
    y = ((M[1][0] * F[0]) % mod + (M[1][1] * F[1]) % mod) % mod;
    int sum = 0;
    loop(i, 0, n) (sum += a[i]) %= mod;
    loop(i, 0, n) b[i] = ((sum - a[i]) + mod) % mod;
    loop(i, 0, n) cout << (x * a[i] + y * b[i]) % mod << endl;
}

signed main() {
    int t = 1; //cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
