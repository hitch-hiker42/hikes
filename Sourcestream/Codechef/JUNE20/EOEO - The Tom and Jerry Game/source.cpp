//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
void hike() {
    int64_t n; cin >> n;
    cout << n / ((n & -n) << 1) << "\n";
}

signed main() {
    int t; cin >> t;
    while(t--) purgatorio();
    return 0;
} //farewell, until we meet again..
