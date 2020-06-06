#include<bits/stdc++.h>
using namespace std;

#define span(v) begin(v), end(v)

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for(int& i: v) cin >> i;
        sort(span(v));
        cout << ((v.back() - v.front()) << 1) << endl;
    }
    return 0;
}
