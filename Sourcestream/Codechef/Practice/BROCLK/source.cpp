//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int int64_t
#define matrix vector<vector<int>>
#define loop(x, start, end) for(int x = start; x < end; ++x)
constexpr int mod = 1000'000'007;


auto multiply(matrix& A, matrix& B) {
    matrix C = {{0, 0}, {0, 0}};
    loop(i, 0, 2) loop(j, 0, 2) loop(k, 0, 2) ((C[i][j] += A[i][k] * B[k][j]) += mod) %= mod;
    return C;
}

auto power(matrix& base, int exp) {
    matrix result = {{1, 0}, {0, 1}};
    while(exp) {
        if(exp & 1) result = multiply(result, base);
        base = multiply(base, base);
        exp >>= 1;
    }
    return result;
}

int raise(int x, int y, int m) {
    int result = 1;
    while(y) {
        if(y & 1) (result *= x) %= m;
        (x *= x) %= m;
        y >>= 1;
    }
    return result;
}

void hike() {
    int l, d, t; cin >> l >> d >> t;
    int cosx = (d * raise(l, mod - 2, mod)) % mod;
    matrix T = {{2 * cosx, -1}, {1, 0}};
    vector<int> F = {cosx, 1};
    T = power(T, t - 1);
    int term = ((T[0][0] * F[0] + T[0][1] * F[1]) + mod) % mod;
    cout << (l * term) % mod << endl;
}

signed main() {
    int t; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
