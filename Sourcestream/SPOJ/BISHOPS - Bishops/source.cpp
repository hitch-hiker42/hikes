//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

#define span(a) begin(a), end(a)

signed main() {
    string n;
    while(cin >> n) {
        if(n == "1") {
            cout << n << endl;
            continue;
        }
        int d = (int)n.length(), carry = 0, i = 0;
        reverse(span(n));
        for(int x, y, z; i < d; ++i) {
            if(n[i] == '0') n[i] = '9'; else break;
        }
        n[i] = n[i] - 1, i = 0;
        for(int x, y, z; i < d; ++i) {
            x = n[i] - '0';
            y = (x << 1) + carry;
            z = y % 10;
            carry = y / 10;
            n[i] = z + '0';
        }
        if(carry) n += (carry + '0');
        reverse(span(n));
        cout << n << endl;
    }
    return 0;
} //farewell, until we meet again..
