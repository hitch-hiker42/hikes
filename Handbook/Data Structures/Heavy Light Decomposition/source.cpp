vector<int> adj[mxn];
int timer, a[mxn], cost[mxn], sub[mxn];
int in[mxn], out[mxn], dp[mxn][18], f[mxn], idx[mxn];
 
int dfs(int u, int p) {
  in[u] = timer++;
  sub[u] = 1, dp[u][0] = p;
  for(int i = 1; i < 18; ++i) {
    dp[u][i] = dp[dp[u][i - 1]][i - 1];
  }
  for(auto& v: adj[u]) {
    if(v != p) {
      sub[u] += dfs(v, u);
    }
  }
  out[u] = timer++;
  return sub[u];
}
 
void hld(int u, int p, int root) {
  f[u] = root;
  idx[u] = timer++;
  cost[idx[u]] = a[u];
  int maxima = 0, heavy = -1;
  for(auto& v: adj[u]) {
    if(v != p and sub[v] > maxima) {
      maxima = sub[v];
      heavy = v;
    }
  }
  if(~heavy) hld(heavy, u, root);
  for(auto& v: adj[u]) {
    if(v != p and v != heavy) {
      hld(v, u, v);
    }
  }
}
 
bool is_ancestor(int u, int v) {
  return in[u] <= in[v] and out[v] <= out[u];
}
 
int lca(int u, int v) {
  if(is_ancestor(u, v)) return u;
  if(is_ancestor(v, u)) return v;
  for(int i = 17; ~i; --i) {
    if(!is_ancestor(dp[u][i], v)) u = dp[u][i];
  }
  return dp[u][0];
}
 
int n, t[mxn << 1];

int merge(int i, int j) {
  return max(i, j);
}

void build() {
  for(int i = 0; i < n; ++i) t[n + i] = cost[i];
  for(int i = n - 1; i; --i) {
    t[i] = merge(t[i << 1], t[(i << 1) | 1]);
  }
}
 
void update(int i, int delta) {
  for(t[i += n] = delta; i > 1; i >>= 1) {
    t[(i >> 1)] = merge(t[i], t[i ^ 1]);
  }
}
 
int query(int lo, int hi) {
  int result = 0;
  for(lo += n, hi += n; lo < hi; lo >>= 1, hi >>= 1) {
    if (lo & 1) result = merge(result, t[lo++]);
    if (hi & 1) result = merge(result, t[--hi]);
  }
  return result;
}

auto jump(int u, int p) {
  int ans = 0;
  while(f[u] != f[p]) {
    ans = merge(ans, query(idx[f[u]], idx[u] + 1));
    u = dp[f[u]][0];
  }
  ans = merge(ans, query(idx[p], idx[u] + 1));
  return ans;
}

auto hldquery(int u, int v) {
  int p = lca(u, v);
  return max(jump(u, p), jump(v, p));
}
