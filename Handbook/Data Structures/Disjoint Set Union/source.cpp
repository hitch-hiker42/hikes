struct dsu {
  int n, parent[lim], size[lim];
  dsu() = default;
  dsu(int n): n(n) {
    for(int i = 1; i <= n; ++i) {
      parent[i] = i, size[i] = 1;
    }
  }
  bool unite(int u, int v) {
    u = find(u), v = find(v);
    if(u != v) {
      if(size[u] < size[v]) swap(u, v);
      size[u] += size[v];
      parent[v] = u;
    }
    return (u != v);
  }
  int find(int u) {
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
  }
};
