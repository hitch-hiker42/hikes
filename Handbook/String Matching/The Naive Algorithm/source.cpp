//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

auto matcher(const string& text, const string& pattern) {
    vector<int> shift;
    int n = (int)text.length(), m = (int)pattern.length();
    for(int i = 0; i <= n - m; ++i) {
        bool match = true;
        for(int j = 0; j < m; ++j) {
            if(text[i + j] != pattern[j]) {
                match = false;
                break;
            }
        }
        if(match) shift.push_back(i);
    }
    return move(shift);
}

void hike() {
    string text, pattern; cin >> text >> pattern;
    auto shift = matcher(text, pattern);
    for(auto& i: shift) cout << i << ' ';
    cout << endl;
}

signed main() {
    int t = 1; //cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
