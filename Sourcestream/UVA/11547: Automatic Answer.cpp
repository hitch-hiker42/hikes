#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        cout << abs(((315 * x + 36962) / 10) % 10) << endl;
    }
    return 0;
}
