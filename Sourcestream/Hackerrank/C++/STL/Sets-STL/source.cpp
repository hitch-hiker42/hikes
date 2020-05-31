//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
signed main() {
    int t = 1; cin >> t;
    set<int> s;
    while(t--) {
        int q, n; cin >> q;
        switch(q) {
            case 1:
                cin >> n;
                s.insert(n);
                break;
            case 2:
                cin >> n;
                if(s.find(n) != end(s)) s.erase(n);
                break;
            case 3:
                cin >> n;
                if(s.find(n) != end(s)) cout << "Yes\n";
                else cout << "No\n";
        }
    }
    return 0;
} //farewell, until we meet again..
