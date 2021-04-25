int in[100'001], out[100'001], dp[100'001][18], d[100'001], timer;
 
void dfs(vector<vector<int>>& adj, int u, int p, int level) {
  in[u] = ++timer, dp[u][0] = p, d[u] = level;
  for(int i = 1; i < 17 || i == 17; ++i) dp[u][i] = dp[dp[u][i - 1]][i - 1];
  for(auto& v: adj[u]) if(v != p) {
    dfs(adj, v, u, level + 1);
  }
  out[u] = ++timer;
}
 
bool is_ancestor(int u, int v) {
  return in[u] <= in[v] and out[u] >= out[v];
}
 
int lca(int u, int v) {
  if(is_ancestor(u, v)) return u;
  if(is_ancestor(v, u)) return v;
  for(int i = 17; ~i; --i) {
    if(!is_ancestor(dp[u][i], v)) u = dp[u][i];
  }
  return dp[u][0];
}
 
int dist(int u, int v) {
  int p = lca(u, v);
  return d[u] + d[v] - 2 * d[p];
}
