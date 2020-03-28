#include<bits/stdc++.h>
using namespace std;

void init(auto& lang) {
    lang["HELLO"] = "ENGLISH";
    lang["HOLA"] = "SPANISH";
    lang["HALLO"] = "GERMAN";
    lang["BONJOUR"] = "FRENCH";
    lang["CIAO"] = "ITALIAN";
    lang["ZDRAVSTVUJTE"] = "RUSSIAN";
}

int main() {
    int i = 1; string s;
    map<string, string> lang;
    init(lang);
    while(getline(cin, s), s != "#") {
        if(lang.find(s) != lang.end()) {
            cout << "Case " << i++ << ": " << lang[s] << endl;
        } else {
            cout << "Case " << i++ << ": Unknown" << endl;
        }
    }
    return 0;
}
