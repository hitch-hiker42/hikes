//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int int64_t
#define endl '\n'

void hike() {
    int a, b; cin >> a >> b;
    if(__gcd(a, b) != 1) {
        cout << -1 << endl;
        return;
    }
    cout << (a - 1) * (b - 1) << endl;
}

signed main() {
    int t; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
