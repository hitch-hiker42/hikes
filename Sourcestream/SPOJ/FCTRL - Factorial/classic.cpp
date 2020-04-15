//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

void hike() {
    int n, p = 5, sum = 0; cin >> n;
    while(p <= n) sum += n / p, p *= 5;
    cout << sum << endl;
}

signed main() {
    int t; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
