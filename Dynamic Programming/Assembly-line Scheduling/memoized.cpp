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
#define pipeline
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
map<int, int> flip = {{1, 2}, {2, 1}};
map<int, vector<int>> dp;
map<int, map<int, int>> line;

void print(int state, int station) {
    if(station < 0) {
        return;
    } else {
        print(line[state][station], station - 1);
        cout << state << ' ';
    }
}

int recurse(auto& a, auto& t, int i, int j) {
    if(dp[i][j] != -1) {
        return dp[i][j];
    } else {
        int cost = recurse(a, t, i, j - 1), flipcost = recurse(a, t, flip[i], j - 1) + t[flip[i]][j - 1];     
        if(cost <= flipcost) {
            line[i][j] = i;
        } else {
            line[i][j] = flip[i];
        }
        return dp[i][j] = min(cost, flipcost) + a[i][j];
    }
}
 
void solution() {
    //input:
    int n, ix, iy, ox, oy;
    cin >> n >> ix >> iy >> ox >> oy;
    map<int, vector<int>> a, t;
    a[1].resize(n, 0); a[2].resize(n, 0);
    t[1].resize(n - 1, 0); t[2].resize(n - 1, 0);
     
    for(int i = 0; i < n; ++i) cin >> a[1][i];
    for(int i = 0; i < n; ++i) cin >> a[2][i];
    for(int i = 0; i < n - 1; ++i) cin >> t[1][i];
    for(int i = 0; i < n - 1; ++i) cin >> t[2][i];

    dp[1].resize(n, -1); dp[1][0] = ix + a[1][0];
    dp[2].resize(n, -1); dp[2][0] = iy + a[2][0];

    //black-box:
    int global = min(recurse(a, t, 1, n - 1) + ox, recurse(a, t, 2, n - 1) + oy), state;
    if(dp[1][n - 1] + ox < dp[2][n - 1] + oy) {
        state = 1;    
    } else {
        state = 2;
    }
    
    //output:
    cout << "Minimum temporal cost: " << global << endl;
    cout << "Sequence of stations that achieves optimal value: " << endl;
    print(state, n - 1);   
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
