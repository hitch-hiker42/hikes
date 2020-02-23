//author: hitch_hiker42;
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  int t = 1; cin >> t;
	while(t--) {
	    long long int n, m; cin >> n >> m;
	    long long int min = n - 1, max = (n * (n + 1)) / 2;
	    if(m >= min and m <= max) {
	        long long int offset = m - min, degsum;
	        if(offset <= n) {
              degsum = 2 * min + offset;
          } else {
	            long long int d = 2 * min + n;
	            degsum = d + 2 * (offset - n);
	        }
	        cout << ceil((long double)degsum / n);
	    } else {
	        cout << "-1";
      }
      cout << '\n';
	}
	return 0;
} //farewell.. until we meet again;
