#include<bits/stdc++.h>
using namespace std;

constexpr int alive = 1;

int main() {
    int t, i = 1; cin >> t;
    vector<int> v(3);
    while(t--) {
        for(int& i: v) cin >> i;
        sort(begin(v), end(v));
        cout << "Case " << i++ << ": " << v[alive] << endl;
    }
    return 0;
}
