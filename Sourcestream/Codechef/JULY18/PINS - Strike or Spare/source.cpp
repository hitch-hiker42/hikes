//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
void hike() {
    int n; cin >> n;
    cout << "1 1";
    for(int i = 0, x = (n >> 1); i <= x; ++i) cout << "0\n"[i == x];
}

signed main() {
    int t; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
