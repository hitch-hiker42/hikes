//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;
 
//solution:
void hike() {
    int a, b, c; cin >> a >> b >> c;
    if(a == 0 and b == 0) {
        if(c == 0) cout << "Yes\n";
        else cout << "No\n";
        return;
    }
    if(c % __gcd(a, b)) cout << "No\n";
    else cout << "Yes\n";
}
 
signed main() {
    int t; cin >> t;
    for(int i = 1; i <= t; cout << "Case " << i << ": ", hike(), ++i);
    return 0;
} //farewell, until we meet again.. 
