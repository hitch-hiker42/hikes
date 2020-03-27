#include<bits/stdc++.h>
using namespace std;

int main() {
    int k;
    auto quadrant = [](int x, int y) {
        if(!x | !y) return "divisa";
        if(x > 0 and y > 0) return "NE";
        if(x < 0 and y > 0) return "NO";
        if(x > 0 and y < 0) return "SE";
        return "SO";
    };
    while(scanf("%d", &k), k) {
        int p, q; cin >> p >> q;
        while(k--) {
            int x, y; cin >> x >> y;
            x -= p; y -= q;
            cout << quadrant(x, y) << endl;   
        }
    }
    return 0;
}
