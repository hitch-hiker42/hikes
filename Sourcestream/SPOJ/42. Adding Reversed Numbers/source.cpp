//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

signed main() {
	int t; cin >> t;
	while(t--) {
		string x, y; cin >> x >> y;
		x.erase(x.find_last_not_of("0") + 1); reverse(begin(x), end(x));
		y.erase(y.find_last_not_of("0") + 1); reverse(begin(y), end(y));
		int m = stoi(x), n = stoi(y);
		string z = to_string(m + n);
		z.erase(z.find_last_not_of("0") + 1);
		cout << string(rbegin(z), rend(z)) << endl;
	}
	return 0;
} //farewell, until we meet again..
