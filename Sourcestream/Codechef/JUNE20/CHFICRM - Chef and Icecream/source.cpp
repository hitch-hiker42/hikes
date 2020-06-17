//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int int64_t

void hike() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> change;
    bool flag = true;
    for(int& i: a) {
        cin >> i;
        if(i == 5) {
            ++change[5];
            continue;
        } else if(i == 10) {
             if(change[5]) {
                ++change[10];
                --change[5];
                continue;
             }
        } else {
            assert(i == 15);
            if(change[10]) {
                ++change[15];
                --change[10];
                continue;
            } else {
                if(change[5] >= 2) {
                    ++change[15];
                    change[5] -= 2;
                    continue;
                }
            }
        }
        flag = false;
    }
    if(flag) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    int t; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
