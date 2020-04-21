//author: hitch_hiker42;
#include <bits/stdc++.h>
using namespace std;

#define span(a) begin(a), end(a)

bool match(string s, string t) { 
    int m = s.length(), n = t.length(); 
    if(m > n) return false; 
    for(int i = 0; i < m; i++) 
       if(s[m - i - 1] != t[n - i - 1])
           return false;
    return true; 
}
    
void hike() {
    int n; cin >> n;
    vector<string> s(n), prefix(n), suffix(n), sub(n);
    vector<array<int, 2>> mid(n);
    for(int i = 0; i < n; ++i) {
        cin >> s[i];
        int k = 0, l = s[i].length() - 1;
        for(int j = 0; j < s[i].length(); ++j) {
            if(s[i][j] == '*') {
                prefix[i] = s[i].substr(0, j);
                k = j + 1;
                break;
            }
        }
        reverse(span(s[i]));
        for(int j = 0; j < s[i].length(); ++j) {
            if(s[i][j] == '*') {
                string x = s[i].substr(0, j);
                reverse(span(x));
                suffix[i] = x;
                l = s[i].length() - (j + 1);
                break;
            }
        }
        reverse(span(s[i]));
        mid[i] = {k, l};
    }
    for(int i = 0; i < n; ++i) {
        for(int j = mid[i][0]; j < mid[i][1]; ++j) {
            if(s[i][j] != '*') sub[i] += s[i][j];
        }
    }
    sort(span(prefix), [](auto& x, auto& y) {
        return x.length() > y.length();
    });
    sort(span(suffix), [](auto& x, auto& y) {
        return x.length() > y.length();
    });
    for(int i = 1; i < prefix.size(); ++i) {
        string x = prefix[i], y = prefix.front();
        reverse(span(x)); reverse(span(y));
        if(!match(x, y)) {
            cout << "*\n";
            return;
        }
    }
    for(int i = 1; i < suffix.size(); ++i) {
        if(!match(suffix[i], suffix.front())) {
            cout << "*\n";
            return;
        }
    }
    cout << prefix.front();
    for(auto& i: sub) cout << i;
    cout << suffix.front() << "\n";
}

#undef span(a)

signed main() {
    int t = unit; cin >> t;
    for(int i = 1; i <= t; cout << "Case #" << i << ": ", hike(), ++i);
    return 0;
} //farewell.. until we meet again;
