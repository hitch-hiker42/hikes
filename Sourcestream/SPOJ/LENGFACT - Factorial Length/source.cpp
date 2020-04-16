//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

#define int int64_t
#define double long double
constexpr double pi = acosl(-1);
constexpr double e = expl(1);

void hike() {
    int n, d = 1; cin >> n;
    if(n > 1) d += n * (log10l(n) - log10l(e)) + 0.5 * (log10l(2 * pi) + log10l(n));
    cout << d << endl;
}

signed main() {
    int t; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
