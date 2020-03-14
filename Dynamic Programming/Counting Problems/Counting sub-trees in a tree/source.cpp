#include<bits/stdc++.h>
using namespace std;

constexpr int lim = 100000;
map<int, vector<int>> g;
int64_t dp[lim + 1];
int vis[lim + 1];

//returns the number of subtrees rooted at vertex u:
int64_t dfs(int u) {
    int64_t& state = dp[u];
    vis[u] = 1;
    if(state != -1) return state;
    state = 1;
    for(int& v: g[u]) {
        if(!vis[v]) {
            state = state * (dfs(v) + 1);   
        }
    }
    return state;
}

int main() {
    int n, s; cin >> n;
    memset(dp, -1, sizeof dp);
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int x, k{0}; cin >> s;
    x = dfs(s);
    for(int i = 1; i <= n; ++i) cout << dp[i] << ' ';
    cout << "Number of subtrees rooted at node " << s << ": " << x << endl;
    cout << "Total number of subtrees of the given tree: " << k << endl;
    return 0;
}
