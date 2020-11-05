//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;
 
//solution:
vector<int> adj[200'001], sub(200'001);

int dfs(int u, int p) {
  sub[u] = 1;
  for(int& v: adj[u]) if(v != p) {
    sub[u] += dfs(v, u);
  }
  return sub[u];
}
 
void hike() {
  int n; cin >> n;
  for(int u = 2; u <= n; ++u) {
    int v; cin >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  for(int i = 1; i <= n; ++i) cout << sub[i] - 1 << ' ';
}
 
signed main() {
  int t = 1; //cin >> t;
  while(t--) hike();
  return 0;
} //farewell, until we meet again..
