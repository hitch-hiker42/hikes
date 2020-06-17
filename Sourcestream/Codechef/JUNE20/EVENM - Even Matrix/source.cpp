//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
using matrix = vector<vector<int>>;

void hike() {
    int n; cin >> n;
    matrix M = matrix(n, vector<int>(n));
    for(int i = 1, k = 1; i <= n; ++i) {
        if(i & 1) {
            for(int j = 1; j <= n; ++j) M[i - 1][j - 1] = k++;
        } else {
            for(int j = n; j; --j) M[i- 1][j - 1] = k++;
        }
    }
    for(auto& i: M) {
        for(int& j: i) cout << j << ' ';
        cout << "\n";
    }
}

signed main() {
    int t; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
