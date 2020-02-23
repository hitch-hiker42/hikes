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
    int n; cin >> n;
    if((n & 1) and (n ^ 1)) { //it can be proved that a Doofish Matrix exists for order 'n' iff 'n' is even (or vacuosly, if 'n' equals 1);
        cout << "Boo" << endl;
    }
    else {
        cout << "Hooray" << endl;
        vector< vector<int> > dfmtrx(n, vector<int>(n)); //the Doofish Matrix of order 'n';
        int sym[n << unit]; //holds the 'index-symmetric equivalents' of elements in top quarter (that lie in the left);
        int clist[n << unit][n]; //holds a running list of columns for each element in the top quarter that it's been included in;
        memset(clist, zero, n * (n << unit) * sizeof(int));

        //fill the principal digonal with unit;
        for(int i = 0; i < n; i++) {
            dfmtrx[i][i] = unit;
        }

        //'triangu-lizing' the matrix along along its secondary diagonal;
        for(int i = 0; i < (n >> unit); i++) {
            for(int j = i + 1, k = 0; j < n - i; j++, k++) {
                dfmtrx[i][j] = 2 * (i + 1) + k; //top quarter;
                dfmtrx[j][i] = 2 * (i + 1) + k + (n - 1); //left quarter;
                sym[dfmtrx[i][j]] = dfmtrx[j][i];
                clist[dfmtrx[i][j]][j] = unit; //not anymore;
            }
        }

        /* constructing the right quarter (the most significant and beautiful step):
        ----------------------------------------------------------------------------------------------------------------------------------
         * so, you are to traverse the matrix such that you're in the i'th row and i'th column in the ith-iteration, call this shape a cross;
         * and you're to do that from the top-left corner to the bottom-right one;
         * fill in the numbers that haven't arleady been filled in the current cross;
         * do it such that all the numbers between 1 and 2N-1 (inclusive) are exhaustively filled in the 2N-1 cells;
         * loop-invariant: in ith iteration, all rows and columns numbered 1 through i-1 satisfy the Doofish Matrix constraints;
         * maintaining the loop invariant throughout the iterations constructs the Doofish Matrix of order N at termination (of the loop);
         ---------------------------------------------------------------------------------------------------------------------------------
         */

        for(int i = 1; i < n; i++) {
            vector<int> pass, missing(n << unit, unit);
            for(int j = 0; j < n; j++) {
                missing[dfmtrx[i][j]] = missing[dfmtrx[j][i]] = zero;
                if((j > i) and (j > (n - (i + 1))))
                    pass.push_back(j);
            }
            for(int& j: pass) {
                for(int m = 2; m <= n - 1; m++) {
                    if(missing[m]) {
                        if(!clist[m][j]) {
                            dfmtrx[i][j] = m;
                            clist[m][j] = unit; //again, not anymore;
                            missing[m] = zero;
                            break;
                        }
                    }
                }
            }
        }
        
        //the last nail: constructing the bottom quarter;
        for(int i = (n >> unit) + 1, k = unit; i < n; i++, k++) {
            for(int j = (n >> unit) - k; j < (n >> unit) - k + (k << unit); j++) {
                dfmtrx[i][j] = sym[dfmtrx[j][i]];
            }
        }
        
        //output:
        for(auto i: dfmtrx) {
           for(int& j: i) {
                cout << j << ' ';
            }
            cout << endl;
        }
    }
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
