//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

signed main() {
    int x, y, z;
    while(cin >> x >> y >> z, x | y | z) {
        if(y - x == z - y) {
            int d = y - x;
            cout << "AP " << z + d << endl;
        } else {
            int r = y / x;
            cout << "GP " << z * r << endl;
        }
    }
    return 0;
} //farewell, until we meet again..
