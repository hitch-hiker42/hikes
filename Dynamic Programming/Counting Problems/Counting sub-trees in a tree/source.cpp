//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

constexpr int lim = 100001;
int64_t dp[lim];
bool vis[lim];

//returns the number of subtrees rooted at vertex u:
int64_t dfs(auto& adj, int u) {
    int64_t& state = dp[u];
    vis[u] = true;
    if(~state) return state;
    state = 1;
    for(int& v: adj[u]) if(!vis[v]) {
        state = state * (dfs(adj, v) + 1);
    }
    return state;
}

int main() {
    int n, s; cin >> n;
    memset(dp, -1, sizeof dp);
    memset(vis, false, sizeof vis);
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    int x, k{0}; cin >> s;
    x = dfs(adj, s);
    for(int i = 1; i <= n; ++i) k += dp[i];
    cout << "Number of subtrees rooted at node " << s << ": " << x << endl;
    cout << "Total number of subtrees of the given tree: " << k << endl;
    return 0;
} //farewell, until we meet again..
