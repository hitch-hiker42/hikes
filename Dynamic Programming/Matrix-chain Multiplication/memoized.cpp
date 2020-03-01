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
vector<vector<int>> dp, s;

//parenthesization:
void parenthesize(int i, int j) {
    if(i == j) {
        cout << i;
    } else {
        cout << '(';
        parenthesize(i, s[i][j]);
        parenthesize(s[i][j] + 1, j);
        cout << ')';
    }
}

//memoization:
int recurse(auto& p, int i, int j) {
    if(dp[i][j] != infmax) {
        return dp[i][j];
    } else if(i == j) {
        return dp[i][j] = 0;    
    } else {
        for(int k = i; k < j; ++k) {
            int cost = recurse(p, i, k) + recurse(p, k + 1, j) + p[i - 1] * p[k] * p[j];
            if(cost < dp[i][j]) {
                dp[i][j] = cost;
                s[i][j] = k;
            }
        }
        return dp[i][j];
    }
}

void solution() {
    //input:
    int n; cin >> n;
    vector<int> p(n + 1);
    for(int& i: p) cin >> i;

    //black-box:
    dp.resize(n + 1, vector<int>(n + 1, infmax));
    s.resize(n + 1, vector<int>(n + 1, 0));
    int global = recurse(p, 1, n);
    
    //output:
    cout << "Number of scalar multiplications in optimal parenthesization: " << global << endl;
    cout << "Optimal parenthesization: ";
    parenthesize(1, n);
    dp.clear();
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

