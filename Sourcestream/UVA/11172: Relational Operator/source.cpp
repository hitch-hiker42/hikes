#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    auto spaceship = [](int x, int y) {
        if(x < y) return '<';
        if(x > y) return '>';
        return '=';
    };
    while(t--) {
        int x, y; cin >> x >> y;
        cout << spaceship(x, y) << endl;
    }
    return 0;
}
