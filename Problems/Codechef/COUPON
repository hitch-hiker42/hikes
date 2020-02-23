//author: hitch_hiker42;
#include <bits/stdc++.h>
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
    //input:
    int64_t n, m; cin >> n >> m;
    int64_t cost[n][m], discount[n][m];
    for(auto& i: cost) for(auto& j: i) cin >> j;
    for(auto& i: discount) for(auto& j: i) cin >> j;

    //black-box:
    int64_t dp[n][m];
    memset(dp, 0, (n * m) * sizeof(int64_t));
    for(int j = 0; j < m; ++j) dp[0][j] = cost[0][j];
    int64_t local = *min_element(dp[0], dp[0] + m); 
    for(int i = 1; i < n; ++i) {
        int64_t partial = numeric_limits<int64_t>::max();
        for(int j = 0; j < m; ++j) {
            dp[i][j] = min(max(int64_t(0), cost[i][j] - discount[i - 1][j]) + dp[i - 1][j], local + cost[i][j]);
            partial = min(local, dp[i][j]);            
        }
        local = partial;
    }
    int64_t global = *min_element(dp[n - 1], dp[n - 1] + m);

    //output:
    cout << global << endl;
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
