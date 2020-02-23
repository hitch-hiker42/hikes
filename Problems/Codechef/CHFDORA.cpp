//author: hitch_hiker42;
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;

//macro definitions and symbolic constants:
#define syncboost ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define loop(i, begin, end) for(__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define span(v) (v).begin(), (v).end()
#define precise(n) cout << fixed; cout << setprecision(n)
#define endl '\n'
#define debug
//#define pipeline
enum constants {zero, unit, two, three, four, five, six, seven, eight, nine, infmin = numeric_limits<int>::min(), infmax = numeric_limits<int>::max(), mod = int(1e9 + 7)};

//debugging:
#ifdef debug
//#define cerr cout //redirect error messages to stdout instead of stderr;
#define trace(...) error(#__VA_ARGS__, __VA_ARGS__)
template <class Qux>
void error(const char* foo, Qux&& bar) {
    cerr << foo << " : " <<  bar << endl;
}
template <class John, class... Doe>
void error(const char* foo, John&& bar, Doe&&... args) {
    const char* comma = strchr(foo + 1, ',');
    cerr.write(foo, comma - foo) << " : " << bar <<" | ";
    error(comma+1, args...);
}
#else
#define trace(...) //define customized trace tool;
#endif

//solution:
void solution() {
    int n, m; cin >> n >> m;
    vector<vector<int>> u(n, vector<int>(m));
    for(auto& i: u) for(int& j: i) cin >> j;
    map<int, set<pair<int, int>>> spiral;
    for(int layer = 1; layer <= ((min(m, n) + 1) >> unit); layer++) {
        //right:
        for(int r = (layer - 1); r < m - (layer - 1); r++) {
            spiral[layer].insert({layer - 1, r});
        }
        //down:
        for(int d = layer; d < n - (layer - 1); d++) {
            spiral[layer].insert({d, m - 1 - (layer - 1)});
        }
        //left:
        for(int l = m - 2 - (layer - 1); l >= (layer - 1); l--) {
            spiral[layer].insert({n - 1 - (layer - 1), l});
        }
        //up:
        for(int u = n - 2 - (layer - 1); u >= layer; u--) {
            spiral[layer].insert({u, (layer - 1)});
        }
    }
    int64_t count(spiral[unit].size());
    int l(unit); spiral.erase(unit);
    for(auto i: spiral) {
        for(auto j: i.second) {
            int plen(unit);
            for(int k = 1; k <= l; k++) {
                if(u[j.first - k][j.second] == u[j.first + k][j.second] and u[j.first][j.second - k] == u[j.first][j.second + k]) {
                    plen++;
                } else {
                    break;
                }
            }
            count += plen;
        }
        l++;
    }
    cout << count << endl;
}

signed main() {
    //auto start = chrono::system_clock::now();
    #ifdef pipeline
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    syncboost; precise(10);
    int t = unit; cin >> t;
    while(t--) {
        solution();
    }
    //cerr << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;
    return 0;
} //farewell.. until we meet again;
