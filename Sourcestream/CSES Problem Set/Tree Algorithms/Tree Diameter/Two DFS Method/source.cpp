//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;
 
//solution:
pair<int, int> dfs(vector<vector<int>>& adj, int u, int p, int d) {
  auto x = make_pair(u, d);
  for(auto& v: adj[u]) if(v != p) {
    auto y = dfs(adj, v, u, d + 1);
    if(y.second > x.second) x = y;
  }
  return x;
}
 
void hike() {
  int n; cin >> n;
  vector<vector<int>> adj(n + 1);
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  auto x = dfs(adj, 1, 0, 0), y = dfs(adj, x.first, 0, 0);
  cout << y.second << "\n";
}
 
signed main() {
  int t = 1; //cin >> t;
  while(t--) hike();
  return 0;
} //farewell, until we meet again..
