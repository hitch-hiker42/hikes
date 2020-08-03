//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int int64_t
#define matrix vector<vector<int>>
constexpr int mod = 1000'000'000;

auto identity(int n) {
    matrix id = matrix(n, vector<int>(n));
    for(int i = 0; i < n; ++i) id[i][i] = 1;
    return move(id);
}

auto multiply(matrix& A, matrix& B, int n) {
    matrix C = matrix(n, vector<int>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < n; ++k) (C[i][j] += A[i][k] * B[k][j] % mod) %= mod;
        }
    }
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
    //input:
    int a, b, c, d, e, f, g, h, n; cin >> a >> b >> c >> d >> e >> f >> g >> h >> n;
    int x = max({a, f, g}), y = max({b, c, e}), m = x + y + 4;
    --a, --b, --c, --e, --f, --g;

    //construction:
    matrix T = matrix(m, vector<int>(m));
    T[0][a] = T[x][x + e] = 1;
    if(b == c) T[0][x + b] = 2; else T[0][x + b] = T[0][x + c] = 1;
    if(f == g) T[x][f] = 2; else T[x][f] = T[x][g] = 1;
    T[0][m - 3] = T[0][m - 4] = d;
    T[x][m - 1] = T[x][m - 2] = h;
    T[x + y][x + y] = d;
    T[x + y + 1][x + y] = T[x + y + 1][x + y + 1] = d;
    T[x + y + 2][x + y + 2] = h;
    T[x + y + 3][x + y + 2] = T[x + y + 3][x + y + 3] = h;
    for(int i = 1; i < x; ++i) T[i][i - 1] = 1;
    for(int i = x + 1; i < x + y; ++i) T[i][i - 1] = 1;
    vector<int> F(m, 1);
    F[0] = F[x] = 3;
    F[x + y + 1] = 0, F[x + y + 3] = 0;
    
    //computation:
    T = power(T, n, m);
    int X = 0, Y = 0;
    for(int i = 0; i < m; ++i) {
        (X += T[0][i] * F[i] % mod) %= mod;
        (Y += T[x][i] * F[i] % mod) %= mod;
    }
    
    //output:
    cout << X << ' ' << Y << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
