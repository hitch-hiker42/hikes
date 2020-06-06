#include<bits/stdc++.h>
using namespace std;

int main() {
    string s; int i = 1;
    map<string, string> hash{{"Hajj", "Hajj-e-Akbar"}, {"Umrah", "Hajj-e-Asghar"}};
    while(getline(cin, s), s != "*") {
        cout << "Case " << i++ << ": " << hash[s] << endl;
    }
    return 0;
}
