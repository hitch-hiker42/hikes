//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

#define int int64_t
#define double long double
#define span(a) begin(a), end(a)

void hike() {
	int n; cin >> n;
	auto digits = [](int n) {
	    double d = 0;
	    for(int i = 1; i < n || i == n; ++i) d += log10l(i);
	    return int(d + 1);
	};
	int d = digits(n);
	string factorial{string(d - 1, '0') += '1'};
	reverse(span(factorial));
	for(int i = 2; i <= n; ++i) {
	    for(int j = 0, x, y, z, carry = 0; j < d; ++j) {
	        x = factorial[j] - '0';
	        y = x * i + carry;
	        z = y % 10;
	        carry = y / 10;
	        factorial[j] = z + '0';
	    }
	}
	reverse(span(factorial));
	cout << factorial << endl;
}

signed main() {
	int t; cin >> t;
	while(t--) hike();
	return 0;
} //farewell, until we meet again..
