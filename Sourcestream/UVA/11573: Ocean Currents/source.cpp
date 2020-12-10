//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
constexpr int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
constexpr int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

void hike() {
  int n, m; cin >> n >> m;
  string s[n];
  for(int i = 0; i < n; ++i) cin >> s[i];
  auto valid = [&](int i, int j) {
    return (i >= 0 and i < n and j >= 0 and j < m);
  };
  int d[n][m], k; cin >> k;
  while(k--) {
    memset(d, 0x3f, sizeof d);
    int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    deque<pair<int, int>> q;
    q.emplace_back(sx - 1, sy - 1);
    d[sx - 1][sy - 1] = 0;
    while(!q.empty()) {
      auto [x, y] = q.front(); q.pop_front();
      for(int r = 0; r < 8; ++r) {
        int u = x + dx[r], v = y + dy[r];
        if(valid(u, v)) {
          int w = (r != s[x][y] - '0');
          if(d[u][v] > d[x][y] + w) {
            d[u][v] = d[x][y] + w;
            w ? q.emplace_back(u, v) : q.emplace_front(u, v);
          }
        }
      }
    }
    cout << d[tx - 1][ty - 1] << "\n";
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1; //cin >> t;
  while(t--) hike();
  return 0;
} //farewell, until we meet again..
