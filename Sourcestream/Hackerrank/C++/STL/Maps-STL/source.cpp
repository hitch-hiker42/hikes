//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
signed main() {
    int t = 1, m; cin >> t;
    map<string , int> test;
    while(t--) {
        string s; int q; cin >> q;
        switch(q) {
            case 1:
                cin >> s >> m;
                test[s] += m;
                break;
            case 2:
                cin >> s;
                test[s] = 0;
                break;
            case 3:
                cin >> s;
                cout << test[s] << "\n";
        }
    }
    return 0;
} //farewell, until we meet again..
