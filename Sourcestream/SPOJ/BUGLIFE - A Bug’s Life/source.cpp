//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

constexpr int MAX = 1'000'001;
bool vis[MAX];
int color[MAX];

bool dfs(auto& adj, int u, int state) {
    vis[u] = true;
    bool test = true;
    for(int& v: adj[u]) {
        if(vis[v]) { //if this vertex has already been discovered, notice that it must have been assigned a color
            if(!(color[v] == state ^ 1)) { //test if there is any inconsistency in coloring
                return false;
            } else {
                continue; //sheer ignorance
            }
        }
        test &= dfs(adj, v, color[v] = state ^ 1); //color and continue deeper in the graph
    }
    return test;
}

void hike() {
    memset(vis, false, sizeof vis);
    memset(color, -1, sizeof color);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    bool bipartite = true;
    for(int i = 1; i <= n; ++i) if(!vis[i]) {
        bipartite &= dfs(adj, i, color[i] = 0);
    }
    if(bipartite) {
        cout << "No suspicious bugs found!\n";
    } else {
        cout << "Suspicious bugs found!\n";
    }
}

signed main() {
    int t; cin >> t;
    for(int i = 1; i < t || i == t; ++i, hike()) {
        cout << "Scenario #" << i << ":\n";
    }
    return 0;
} //farewell, until we meet again..
