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
enum constants {zero, unit, two, three, four, five, six, seven, eight, nine, mod = int(1e9 + 7), infmin = numeric_limits<int>::min(), infmax = numeric_limits<int>::max()};

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
    string a, b; cin >> a >> b;
    int m = a.length(), n = b.length(), complexity(0);
    for(const char& i: b) {
        if(i == '1') {
            complexity = unit;
            break;
        }
    }
    if(m < n) {
        swap(m, n);
        swap(a, b);
    }
    string prefix(m - n, '0'), u(m, '0'), v(m, '0');
    b = prefix + b;
    for(int i = 0; i < m; i++) {
        u[i] = ((a[i] - '0') ^ (b[i] - '0')) + '0';
        v[i] = ((a[i] - '0') & (b[i] - '0')) + '0';
    }
    u = '0' + u;
    for(int i = m - 1; i >= 0; i--) {
        if(v[i] == '1') {
            int j = i, counter(unit);
            do {
                if(u[j] == '1') {
                    counter++;
                } else {
                    break;
                }
                --j;
            } while(j >= 0);
            ++counter;
            if(counter > complexity) {
                complexity = counter;
            }
        }
    }
    cout << complexity << endl;
};

signed main() {
    //auto start = chrono::system_clock::now();
    #ifdef pipeline
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    syncboost;
    precise(10);
    int t = unit; cin >> t;
    while(t--) {
        solution();
    }
    //cerr << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;
    return 0;
} //farewell.. until we meet again;
