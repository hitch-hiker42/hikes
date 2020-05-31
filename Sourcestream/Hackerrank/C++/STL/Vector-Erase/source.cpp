//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
signed main() {
    int n; cin >> n;
    vector<int> v(n);
    for(int& i: v) cin >> i;
    int x; cin >> x, --x;
    v.erase(begin(v) + x);
    int a, b; cin >> a >> b, --a, --b;
    v.erase(begin(v) + a, begin(v) + b);
    cout << (int)v.size() << "\n";
    for(int& i: v) cout << i << " ";
} //farewell, until we meet again..
