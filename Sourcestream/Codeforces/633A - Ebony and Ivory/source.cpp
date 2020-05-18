//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;
 
void hike() {
    int a, b, c; cin >> a >> b >> c;
    for(int x = 0; a * x <= c; ++x) {
        if((c - a * x) % b == 0) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}
 
signed main() {
    int t = 1; //cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
