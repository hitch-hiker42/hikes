//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

constexpr int MAX = 100'000;
bool vis[MAX];

void dfs(auto& adj, int u) {
    vis[u] = true;
    for(int& v: adj[u]) if(!vis[v]) dfs(adj, v);
}

void hike() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    int components = 0;
    memset(vis, false, sizeof vis);
    for(int i = 0; i < n; ++i) if(!vis[i]) {
        dfs(adj, i);
        components = components + 1;
    }
    cout << components << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
