#include<bits/stdc++.h>
using namespace std;

int main() {
    bitset<3> bit[3] = {3, 5, 6};
    string one = "one";
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        if(s.length() == 5) {
            cout << 3 << endl;
        } else {
            bool x = false;
            for(auto& i: bit) {
                bool y = true;
                for(int j = 0; j < 3; ++j) {
                    if(i[j] && s[j] != one[j]) {
                        y = false;
                        break;
                    }
                }
                if(y) {
                    x = true;
                    break;
                }
            }
            if(x) cout << 1 << endl; else cout << 2 << endl;
        }
    }
    return 0;
}
