#include<bits/stdc++.h>
using namespace std;

int main() {
    int state = 0;
    string s = "", t = "", u = "";
    while(getline(cin, t)) s += t + "\n";
    for(char& i: s) {
        if(i == '\"') {
            u += state++ & 1 ? "''": "``";
        } else {
            u += i;
        }
    }
    cout << u;
    return 0;
}
