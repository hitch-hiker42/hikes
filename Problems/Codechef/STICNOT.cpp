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
    int64_t n, counter(0); cin >> n;
    multiset<int> nodes;
    vector<int> edges(n - 1);
    for(int& i: edges) {
        int64 skip; cin >> skip >> skip >> i;
    }
    for(int i = 0; i < n; i++) {
        int nodeweight; cin >> nodeweight;
        nodes.insert(nodeweight);
    }
    sort(span(edges));
    vector<pair<int, int>> matching;
    for(int& i: edges) {
        auto hold = nodes.lower_bound(i);
        if(hold == nodes.end()) {
            counter++;
        } else {
            matching.push_back({i, *hold});
            nodes.erase(hold);
        }   
    }
    if(counter == 0) {
        if(*nodes.begin() < *edges.rbegin()) {
            counter++;
        }
        cout << counter << endl;
    } else {
        cout << counter + unit << endl;
    }
}

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
