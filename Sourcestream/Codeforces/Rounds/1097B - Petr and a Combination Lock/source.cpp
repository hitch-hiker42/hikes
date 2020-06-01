//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
void hike() {
    int n; cin >> n;
    vector<int> a(n);
    for(int& i: a) cin >> i;
    for(int mask = 0, x = 1 << n; mask < x; ++mask) {
        int64_t sum = 0;
        for(int i = 0; i < n; ++i) {
            if(mask & (1 << i)) sum += a[i];
            else sum -= a[i];
        }
        if(sum % 360 == 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main() {
    int t = 1; //cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
