#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, i = 1; cin >> t;
    while(t--) {
        int l, w, h; cin >> l >> w >> h;
        if(l <= 20 and w <= 20 and h <= 20) {
          cout << "Case " << i++ << ": good" << endl;
        } else {
          cout << "Case " << i++ << ": bad" << endl;
        }
    }
    return 0;
}
