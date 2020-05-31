//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while(T--) {
        double A; cin >> A;
        double B; cin >> B;
        double C; cin >> C;
        cout << hex << showbase << nouppercase << left << (int64_t)A << "\n";
        cout << setprecision(2) << fixed << showpos << right << setfill('_') << setw(15) << B << "\n";
        cout << setprecision(9) << scientific << uppercase << noshowpos << C << "\n";
    }
    return 0;
} //farewell, until we meet again..
