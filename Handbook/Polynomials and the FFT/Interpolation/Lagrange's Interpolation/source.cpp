//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

double lagrange(auto& p, double x) {
    double y = 0;
    for(int i = 0, n = (int)p.size(); i < n; ++i) {
        double kx = p[i][0], ky = p[i][1], l = 1;
        for(int j = 0; j < n; ++j) {
            if(j != i) {
                l *= (x - p[j][0]) / (kx - p[j][0]);
            }
        }
        y += ky * l;
    }
    return y;
}

void hike() {
    int n; cin >> n;
    vector<array<double, 2>> p(n);
    for(auto& i: p) cin >> i[0] >> i[1];
    double x; cin >> x;
    cout << lagrange(p, x) << endl;
}

signed main() {
    int t = 1; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
