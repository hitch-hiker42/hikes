//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int int64_t
#define span(a) begin(a), end(a)

void hike(string& s, string& t) {
  int n = s.length();
  int m = t.length();
  s = "$" + s;
  t = "$" + t;
  int dp[n + 1][m + 1];
  memset(dp, 0, sizeof dp);
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      if(s[i] == t[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        continue;
      }
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  cout << dp[n][m] << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  string s, t;
  while(getline(cin, s)) {
    getline(cin, t);
    hike(s, t);
  }
  return 0;
} //farewell, until we meet again..
