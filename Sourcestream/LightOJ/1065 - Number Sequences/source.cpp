//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;
 
//solution:
#define int int64_t
#define endl '\n'
#define matrix vector<vector<int>>
constexpr int k = 2;
 
auto gcd(int a, int b) {
    if(!b) return make_tuple(a, (int)1, (int)0);
    int d, x, y; tie(d, x, y) = gcd(b, a % b);
    return make_tuple(d, y, x - (a / b) * y);
}
 
int crt(const vector<array<int, 2>>& a, int n) {
    int result = 0;
    for(auto& i: a) {
        int r = i[0], m = i[1], k = n / m;
        int x = get<1>(gcd(k, m));
        result += ((x * k) % n * r) % n;
    }
    return (result + n) % n;
}
 
auto multiply(matrix& A, matrix& B, int m) {
    matrix C = {{0, 0}, {0, 0}};
    for(int p = 0; p < k; ++p) {
        for(int q = 0; q < k; ++q) {
            for(int r = 0; r < k; ++r) {
                (C[p][q] += A[p][r] * B[r][q]) %= m;
            }
        }
    }
    return move(C);
}
 
auto power(matrix base, int exp, int m) {
    matrix result = {{1, 0}, {0, 1}};
    while(exp) {
        if(exp & 1) result = multiply(result, base, m);
        base = multiply(base, base, m);
        exp >>= 1;
    }
    return move(result);
}
 
void hike() {
    int a, b, n, m; cin >> a >> b >> n >> m;
    vector<int> F{b, a};
    int modulus = (int)powl(10, m);
    if(n <= 1) {
        cout << F[n ^ 1] % modulus << endl;
        return;
    }
    int mod[2] = {(int)powl(2, m), (int)powl(5, m)};
    matrix T{{1, 1}, {1, 0}}, X, Y;
    X = power(T, n - 1, mod[0]);
    Y = power(T, n - 1, mod[1]);
    int x = 0, y = 0, term;
    for(int i = 0; i < k; ++i) (x += X[0][i] * F[i]) %= mod[0];
    for(int i = 0; i < k; ++i) (y += Y[0][i] * F[i]) %= mod[1];
    vector<array<int, 2>> r = {{x, mod[0]}, {y, mod[1]}};
    term = crt(r, modulus); cout << term << endl;
}
 
signed main() {
    int t; cin >> t;
    for(int i = 1; i <= t; cout << "Case " << i++ << ": ", hike());
    return 0;
} //farewell, until we meet again..
