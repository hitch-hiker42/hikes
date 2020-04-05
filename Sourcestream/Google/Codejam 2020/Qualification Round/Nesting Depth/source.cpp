//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

void hike() {
    string s, t = ""; cin >> s;
    int v = 0, b = 0;
    for(char& i: s) {
        v = i - '0';
        if(v == b) {
            t += i;
        } else if(v > b) {
            int d = v - b;
            t += string(d, '(') + i;
            b += d;
        } else {
            int d = b - v;
            t += string(d, ')') + i;
            b -= d;
        }
    }
    t += string(b, ')');
    cout << t << endl;
}

int main() {
    int t; cin >> t; 
    for(int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        hike(); //peace is but within;
    }
    return 0;
} //farewell, until we meet again..
