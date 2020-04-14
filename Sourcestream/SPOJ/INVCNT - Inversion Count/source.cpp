#include<bits/stdc++.h>
using namespace std;

#define int int64_t
#define span(v) begin(v), end(v)
#define endl '\n'

constexpr int sentinel = numeric_limits<int>::max();

int merge(auto& a, int lo, int mid, int hi) {
	int p = mid - lo + 1, q = hi - mid, inv = 0;
	vector<int> left, right;
	copy_n(begin(a) + lo, p, back_inserter(left));
	copy_n(begin(a) + mid + 1, q, back_inserter(right));
	left.emplace_back(sentinel); right.emplace_back(sentinel);
	register int i = 0, j = 0, k = lo;
	while(k <= hi) {
		if(left[i] <= right[j]) {
			a[k++] = left[i++];
		} else {
			inv += p - i;
			a[k++] = right[j++];
		}
	}
	return inv;
}

int mergesort(auto& a, int lo, int hi) {
	int inv{0};
	if(lo < hi) {
		int mid  = lo + ((hi - lo) >> 1);
		inv += mergesort(a, lo, mid) + mergesort(a, mid + 1, hi) + merge(a, lo, mid, hi);
	}
	return inv;
}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for_each(span(a), [&](int& i) {
		cin >> i;
	});
	cout << mergesort(a, 0, n - 1) << endl;	
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
