//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int int64_t

void hike() {
    int n, m, k = 0; cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        if(x % m == 0) ++k;
    }
    cout << (1 << k) - 1 << "\n";
}

signed main() {
    int t; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
