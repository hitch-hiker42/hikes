struct decomposition {
  int n;
  vector<set<int>> adj;
  vector<int> parent, ans, sub;
  decomposition(vector<set<int>>& adj, int n): adj(adj), n(n) {
    parent.assign(n + 1, 0);
    ans.assign(n + 1, inf);
    sub.assign(n + 1, 1);
    decompose(n, 1, 0);
  }
  int subtree(int u, int p) {
    sub[u] = 1;
    for(auto& v: adj[u]) if(v != p) {
      sub[u] += subtree(v, u);
    }
    return sub[u];
  }
  int centroid(int m, int u, int p) {
    for(auto& v: adj[u]) if(v != p) {
      if(sub[v] > (m >> 1)) return centroid(m, v, u);
    }
    return u;
  }
  void decompose(int m, int u, int p) {
    subtree(u, p);
    int c = centroid(sub[u], u, p);
    parent[c] = p;
    for(auto& v: adj[c]) {
      adj[v].erase(c);
      decompose(sub[v], v, c);
    }
  }
  void update(int u) {
    for(int v = u; v; v = parent[v]) {
      ans[v] = min(ans[v], dist(u, v));
    }
  }
  int query(int u) {
    int result = ans[u];
    for(int v = u; v; v = parent[v]) {
      result = min(result, dist(u, v) + ans[v]);
    }
    return result;
  }
};
