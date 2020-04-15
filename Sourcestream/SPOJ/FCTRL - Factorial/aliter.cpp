//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

int64_t itoa(int64_t n, int64_t k = 10) {
	if(!n) return 0;
	return (n % k) + 10 * itoa(n / k, k);
}

void hike() {
	int64_t n, x, sum = 0; cin >> n, x = itoa(n, 5);
	while(x) sum += x % 10, x /= 10;
	cout << (n - sum) / 4 << endl;
}

signed main() {
	int t; cin >> t;
	while(t--) hike();
	return 0;
} //farewell, until we meet again;
