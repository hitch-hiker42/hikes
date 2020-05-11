//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int int64_t
constexpr int MAX = (int)1e18;

int search(int a, int b, int c, int d, int k) {
    int lo = 0, hi = (int)cbrtl(MAX / a);
    auto f = [&](int x) {
        return a * x * x * x + b * x * x + c * x + d;
    };
    int result = MAX;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if(f(mid) >= k) {
            result = min(result, mid);
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return max((int)0, result - 1);
}

void hike() {
    int a, b, c, d, k; cin >> a >> b >> c >> d >> k;
    cout << search(a, b, c, d, k) << endl;
}

signed main() {
    int t; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
