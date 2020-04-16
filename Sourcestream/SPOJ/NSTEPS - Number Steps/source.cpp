//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

void hike() {
    int x, y; cin >> x >> y;
    if(!(y == x || y == x - 2)) {
        cout << "No Number" << endl;
        return;
    }
    if(y == x) {
        if(x & 1) {
            cout << 2 * x - 1 << endl;
        } else {
            cout << 2 * x << endl;
        }
    } else {
        if(x & 1) {
            cout << 2 * x - 3 << endl;
        } else {
            cout << 2 * x - 2 << endl;
        }
    }
}

signed main() {
    int t; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
