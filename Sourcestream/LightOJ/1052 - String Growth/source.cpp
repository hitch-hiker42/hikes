//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int int64_t
#define endl '\n'
#define matrix vector<vector<int>>
constexpr int mod = 1000'000'007;
constexpr int k = 2;

auto multiply(matrix& A, matrix& B) {
    matrix C = {{0, 0}, {0, 0}};
    for(int p = 0; p < k; ++p) {
        for(int q = 0; q < k; ++q) {
            for(int r = 0; r < k; ++r) {
                (C[p][q] += A[p][r] * B[r][q]) %= mod;
            }
        }
    }
    return move(C);
}

auto power(matrix base, int exp) {
    matrix result = {{1, 0}, {0, 1}};
    while(exp) {
        if(exp & 1) result = multiply(result, base);
        base = multiply(base, base);
        exp >>= 1;
    }
    return move(result);
}

void hike() {
    int n, x, m, y, k; cin >> n >> x >> m >> y >> k;
    matrix T{{1, 1}, {1, 0}}, N, M;
    N = power(T, n); M = power(T, m);
    matrix A = {{M[0][1], -N[0][1]}, {-M[0][0], N[0][0]}};
    int a = N[0][0], b = N[0][1], c = M[0][0], d = M[0][1];
    if(a * d - b * c == 0) {
        cout << "Impossible\n";
        return;
    }
    int det = a * d - b * c;
    int X = A[0][0] * x + A[0][1] * y, Y = A[1][0] * x + A[1][1] * y;
    if(X % det || Y % det) {
        cout << "Impossible\n";
        return;
    }
    X /= det, Y /= det;
    if(X < 0 || Y < 0 || X + Y == 0) {
        cout << "Impossible\n";
        return;
    }
    T = power(T, k);
    cout << (T[0][0] * X + T[0][1] * Y) % mod << endl;
}

signed main() {
    int t; cin >> t;
    for(int i = 1; i <= t; cout << "Case " << i++ << ": ", hike());
    return 0;
} //farewell, until we meet again..
