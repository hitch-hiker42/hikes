//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int int64_t
constexpr int MAX = 100'000;

int search(int a, int b, int c, int k) {
    int lo = 0, hi = MAX;
    auto f = [&](int x) {
        return a * x * x + b * x + c;
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
    return result;
}

void hike() {
    int a, b, c, k; cin >> a >> b >> c >> k;
    cout << search(a, b, c, k) << endl;
}

signed main() {
    int t; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
