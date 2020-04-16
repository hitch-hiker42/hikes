//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

#define span(a) begin(a), end(a)
vector<deque<int>> paths;

void dfs(auto& adj, auto& branch, int u, int p) {
    bool leaf = true;
    for(auto& v: adj[u]) if(v != p) {
        branch.push_back(v);
        leaf = false;
        dfs(adj, branch, v, u);
        branch.pop_back();
    }
    if(leaf) paths.push_back(branch);
}

void hike() {
    int n; cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    deque<int> branch;
    branch.push_back(1);
    dfs(adj, branch, 1, 0);
    for(auto& i: paths) {
        for(auto& j: i) cout << j << ' ';
        cout << endl;
    }
    paths.clear();
}

signed main() {
    int t; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
