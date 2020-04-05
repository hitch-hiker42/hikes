//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

void hike() {
    int n, k = 0, r = 0, c = 0; cin >> n;
    int a[n][n];
    for(auto& i: a) for(auto& j: i) cin >> j;
    for(int i = 0; i < n; ++i) {
        set<int> p, q;
        for(int j = 0; j < n; ++j) {
            p.insert(a[i][j]);
            q.insert(a[j][i]);
        }
        if(!(p.size() == n)) ++r;
        if(!(q.size() == n)) ++c;
        k += a[i][i];
    }
    cout << k << ' ' << r << ' ' << c << endl;
}

int main() {
    int t; cin >> t; 
    for(int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        hike(); //every moment you pass through, be happy in it;
    }
    return 0;
} //farewell, until we meet again;
