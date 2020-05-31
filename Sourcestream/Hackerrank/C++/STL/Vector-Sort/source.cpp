//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
signed main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int& i: a) cin >> i;
    sort(begin(a), end(a));
    for(int& i: a) cout << i << " ";
    return 0;
} //farewell, until we meet again..
