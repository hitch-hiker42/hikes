//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;
 
//solution:
int dp1[200'001], dp2[200'001];
 
void dfs(vector<vector<int>>& adj, int u, int p) {
  int x = 0, y = 0;
  for(auto& v: adj[u]) if(v != p) {
    dfs(adj, v, u);
    if(dp1[v] + 1 >= y) {
      tie(x, y) = make_pair(y, dp1[v] + 1);
    }
  }
  tie(dp1[u], dp2[u]) = make_pair(y, x + y);
}
 
void hike() {
  int n, dp = 0; cin >> n;
  vector<vector<int>> adj(n + 1);
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(adj, 1, 0);
  for(int i = 1; i <= n; ++i) dp = max(dp, dp2[i]);
  cout << dp << "\n";
}
 
signed main() {
  int t = 1; //cin >> t;
  while(t--) hike();
  return 0;
} //farewell, until we meet again..
