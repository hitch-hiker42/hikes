//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;
 
 //solution:
#define int long long int
int dp[400][400], p[400];

int rsq(int l, int r) {
    if(!l) return p[r];
    return p[r] - p[l - 1];
}

int recurse(int i, int j) {
    auto& state = dp[i][j];
    if(state != -1) return state;
    if(i == j) return state = 0;
    int cost = rsq(i, j);
    state = numeric_limits<int>::max();
    for(int k = i; k < j; ++k) {
        state = min(state, recurse(i, k) + recurse(k + 1, j) + cost);
    }
}
 
signed main() {
    int n; cin >> n;
    int s[n];
    for(int i = 0; i < n; ++i) cin >> s[i];
    memset(dp, -1, sizeof dp);
    p[0] = s[0];
    for(int i = 1; i < n; ++i) p[i] = p[i - 1] + s[i];
    cout << recurse(0, n - 1);
    return 0;
} //farewell, until we meet again..
