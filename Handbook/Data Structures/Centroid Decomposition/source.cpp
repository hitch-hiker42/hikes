struct centroid {
  int n;
  centroid(vector<vector<int>>& adj, int n): n(n) {
    // memset(dead, 0, (n + 1) * sizeof(int));
    decompose(adj, n, 1, 0);
  }
  int subtree(vector<vector<int>>& adj, int u, int p) {
    sub[u] = 1;
    for(int& v: adj[u]) if(v != p and !dead[v]) {
      sub[u] += subtree(adj, v, u);
    }
    return sub[u];
  }
  int find(vector<vector<int>>& adj, int u, int p, int m) {
    for(int& v: adj[u]) if(v != p and !dead[v]) {
      if(sub[v] > (m >> 1)) return find(adj, v, u, m);
    }
    return u;
  }
  void decompose(vector<vector<int>>& adj, int m, int u, int p) {
    subtree(adj, u, p);
    int c = find(adj, u, p, sub[u]);
    dead[c] = 1, parent[c] = p;
    for(int& v: adj[c]) if(!dead[v]) {
      decompose(adj, sub[v], v, c);
    }
  }
  int operator[] (int u) {
  	return parent[u];
  }
};
