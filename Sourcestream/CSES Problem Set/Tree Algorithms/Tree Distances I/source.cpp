//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
constexpr int lim = 200'001;
vector<int> adj[lim], x(lim), y(lim), q(lim), r(lim);

void get(int u, int v, int t) {
  if(t) swap(x[v], y[v]);
  if(y[v] + 1 >= x[u]) {
    if(y[v] + 1 >= y[u]) {
      tie(x[u], y[u]) = make_pair(y[u], y[v] + 1);
      tie(q[u], r[u]) = make_pair(r[u], v);
    } else {
      x[u] = y[v] + 1;
      q[u] = v;
    }
  }
  if(t) swap(x[v], y[v]);
}

void dfs(int u, int p) {
  for(int& v: adj[u]) if(v != p) {
    dfs(v, u), get(u, v, 0);
  }
}

void dfs2(int u, int p) {
  if(p != 0) {
    if(r[p] != u) get(u, p, 0);
    else get(u, p, 1);
  }
  for(int& v: adj[u]) if(v != p) dfs2(v, u);
}

void hike() {
  int n; cin >> n;
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0), dfs2(1, 0);
  for(int i = 1; i <= n; ++i) cout << y[i] << ' ';
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1; //cin >> t;
  while(t--) hike();
  return 0;
} //farewell, until we meet again..
