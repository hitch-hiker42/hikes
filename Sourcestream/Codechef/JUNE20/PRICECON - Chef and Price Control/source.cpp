//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int int64_t

void hike() {
    int n, k; cin >> n >> k;
    vector<int> p(n);
    int loss = 0;
    for(int& i: p) cin >> i, loss += i - min(i, k);
    cout << loss << "\n";
}

signed main() {
    int t; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
