//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

void hike() {
    int64_t n;
    while(cin >> n, n) {
        cout << (n * (n + 1) * (2 * n + 1)) / 6 << endl;   
    }
}

signed main() {
    int t = 1; //cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
