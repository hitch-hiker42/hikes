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
int solution() {
    int64_t n, profit(infmin), request[4][4]; cin >> n;
    memset(request, zero, 4 * 4 * sizeof(int64_t));
    map<char, int> mnorm({{'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}});
    map<int, int> tnorm({{12, 0}, {3, 1}, {6, 2}, {9, 3}});
    for(int i = 0; i < n; ++i) {
        char m; int t; cin >> m >> t;
        request[mnorm[m]][tnorm[t]]++;
    }
    string s("ABCD");
    do {
        int64_t t = 0, local = 0; vector<int64_t> p;
        for(char& m: s) {
            p.push_back(request[mnorm[m]][t]);
            ++t;
        }
        sort(span(p)); t = 0;
        for(int64_t& i: p) {
            i ? local += (i * (t + 1) * 25) : local -= 100;
            ++t;
        }
        profit = max(profit, local);
    } while(next_permutation(span(s)));
    cout << profit << endl; return profit;
}

signed main() {
    //auto start = chrono::system_clock::now();
    #ifdef pipeline
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    syncboost; precise(10);
    int64_t t = unit, sum = zero; cin >> t;
    while(t--) {
        sum += solution();
    }
    cout << sum << endl;
    //cerr << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;
    return 0;
} //farewell.. until we meet again;
