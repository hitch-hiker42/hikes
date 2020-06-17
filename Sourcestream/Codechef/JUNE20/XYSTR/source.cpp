//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
void hike() {
    string s; cin >> s;
    int m[s.length()] = {}, count = 0;
    for(int i = 1, n = s.length(); i < n; ++i) {
        if(s[i] != s[i - 1] and !m[i - 1]) {
            m[i] = m[i - 1] = 1;
            count = count + 1;
        }
    }
    cout << count << "\n";
}

signed main() {
    int t; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
