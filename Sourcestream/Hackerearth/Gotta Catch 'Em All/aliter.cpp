//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
constexpr int lim = 241; //http://oeis.org/A066150

signed main() {
    int t, n; cin >> t >> n;
    int x[n + 1] = {}, y[lim] = {};
    //x[i]: the number of divisors of i
    //y[i]: count of numbers (1 <= j <= n) having at most i divisors
    for(int i = 1; i <= n; ++y[x[i]], ++i) {
        for(int j = i; j <= n; ++x[j], j += i);
    }
    for(int i = 1; i < lim; ++i) y[i] += y[i - 1];
    for(int i = 0, k; i < t; ++i) {
        cin >> k; cout << y[x[k] - 1] << endl;
    }
    return 0;
} //farewell, until we meet again..
