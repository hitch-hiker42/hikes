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
void parenthesize(auto& s, int i, int j) {
    if(i == j) {
        cout << i;
    } else {
        cout << '(';
        parenthesize(s, i, s[i][j]);
        parenthesize(s, s[i][j] + 1, j);
        cout << ')';
    }
}
          
void solution() {
    //input:
    int n; cin >> n;
    vector<int64_t> p(n + 1);
    for(int i = 0; i <= n; ++i) {
        cin >> p[i];
    }
    
    //black-box:
    int64_t dp[n + 1][n + 1];
    memset(dp, zero, (n + 1) * (n + 1) * sizeof(int64_t));
    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));               
    for(int l = 2; l <= n; ++l) {      
        for(int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            dp[i][j] = infmax;
            for(int k = i; k < j; ++k) {
                int64_t local = dp[i][k] + dp[k + 1][j] + (p[i - 1] * p[k] * p[j]);              
                if(local < dp[i][j]) {
                    dp[i][j] = local;
                    s[i][j] = k;
                }                           
            }
        }
    }

    //output:
    cout << "Number of scalar multiplications in the optimal parenthesization: " << dp[1][n] << endl;
    cout << "Optimal parenthesization: ";
    parenthesize(s, 1, n);
    cout << endl;
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
