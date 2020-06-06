#include<bits/stdc++.h>
using namespace std;

constexpr int offset = 1080, m = 40;

int main() {
    string s;
    while(getline(cin, s)) {
        istringstream input(s);
        int p, x, y, z, result = 0;
        input >> p >> x >> y >> z;
        if(!(p | x | y | z)) break;
        result += ((p - x) + m) % m;
        result += ((y - x) + m) % m;
        result += ((y - z) + m) % m;
        cout << 9 * result + offset << endl;
    }
    return 0;
}
