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
void print(auto& line, int state, int station) {
    if(station < 0) {
        return;
    } else {
        print(line, line[state][station], station - 1);
        cout << state << ' ';
    }
}

void solution() {
    //input:
    int n, ix, iy, ox, oy;
    cin >> n >> ix >> iy >> ox >> oy;
    int ax[n], ay[n], tx[n - 1], ty[n - 1], fx[n], fy[n];
    map<int, map<int, int>> line;
     
    for(int i = 0; i < n; ++i) cin >> ax[i];
    for(int i = 0; i < n; ++i) cin >> ay[i];
    for(int i = 0; i < n - 1; ++i) cin >> tx[i];
    for(int i = 0; i < n - 1; ++i) cin >> ty[i];    
    
    auto minima = [&](int x, int y) {
        if(x <= y) {
            return unit; //assembly line one;
        } else {
            return two; //assembly line two;
        }
    };

    //bottom-up tabulation:
    fx[0] = ax[0] + ix;
    fy[0] = ay[0] + iy;          
    for(int i = 1; i < n; ++i) {                                                                                 
        fx[i] = min(fx[i - 1] + ax[i], fy[i - 1] + ty[i - 1] + ax[i]);
        fy[i] = min(fy[i - 1] + ay[i], fx[i - 1] + tx[i - 1] + ay[i]);
        line[1][i] = minima(fx[i - 1] + ax[i], fy[i - 1] + ty[i - 1] + ax[i]);
        line[2][i] = minima(fx[i - 1] + tx[i - 1] + ay[i], fy[i - 1] + ay[i]);
    }
    
    //optimal-value:
    cout << "Minimum temporal cost: " << min(fx[n - 1] + ox, fy[n - 1] + oy) << endl;
    
    //output(optimal-solution):
    int state = minima(fx[n - 1] + ox, fy[n - 1] + oy);
    cout << "Sequence of stations that achieves optimal value: " << endl;
    print(line, state, n - 1);
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