#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, run = 0; cin >> t;
    while(t--) {
        string s; cin >> s;
        if(s == "donate") {
            int x; cin >> x, run += x;
        } else {
            cout << run << endl;
        }
    }
    return 0;
}
