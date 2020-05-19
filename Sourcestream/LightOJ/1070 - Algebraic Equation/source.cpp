//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;
 
//solution:
#define endl '\n'
#define int uint64_t
#define matrix vector<vector<int>>
 
auto identity(int n) {
    matrix id = matrix(n, vector<int>(n));
    for(int i = 0; i < n; ++i) id[i][i] = 1;
    return move(id);
}
 
auto multiply(matrix& A, matrix& B, int n) {
    matrix C = matrix(n, vector<int>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < n; ++k) C[i][j] += A[i][k] * B[k][j];
        }
    }
    return move(C);
}
 
auto power(matrix base, int exp, int n) {
    matrix result = identity(n);
    while(exp) {
        if(exp & 1) result = multiply(result, base, n);
        base = multiply(base, base, n);
        exp >>= 1;
    }
    return move(result);
}
 
void hike() {
    int p, q, n; cin >> p >> q >> n;
    matrix T = {{p, -q}, {1, 0}};
    vector<int> F = {p, 2};
    if(n <= 1) {
        cout << F[n ^ 1] << endl;
        return ;
    }
    T = power(T, n - 1, 2);
    cout << T[0][0] * F[0] + T[0][1] * F[1] << endl;
}
 
signed main() {
    int t; cin >> t;
    for(int i = 1; i <= t; cout << "Case " << i++ << ": ", hike());
    return 0;
} //farewell, until we meet again..
