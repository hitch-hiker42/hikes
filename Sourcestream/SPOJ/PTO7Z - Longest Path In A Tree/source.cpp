//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

pair<int, int> dfs(auto& adj, int u, int p, int lvl) {
	pair<int, int> global = {u, lvl};
	for(auto& v: adj[u]) if(v != p) {
		auto local = dfs(adj, v, u, lvl + 1);
		if(local.second > global.second) global = local;
	}
	return global;
}

void hike() {
	int n; cin >> n;
	vector<vector<int>> adj(n);
	for(int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u - 1].emplace_back(v - 1);
		adj[v - 1].emplace_back(u - 1);
	}
	auto x = dfs(adj, 0, -1, 0), y = dfs(adj, x.first, -1, 0);
	cout << y.second << endl;
}

signed main() {
	int t = 1; //cin >> t;
	while(t--) hike();
	return 0;
} //farewell, until we meet again..
