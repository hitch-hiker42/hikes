//author: hitch_hiker42;
#include "bits/stdc++.h"
using namespace std;
 
//solution:
#define int int64_t
constexpr int infmin = numeric_limits<int>::min();
constexpr int infmax = numeric_limits<int>::max();
 
auto sign = [](int x) { 
    return (x > 0) - (x < 0);
};
 
auto gcd(int a, int b) {
    if(!b) return make_tuple(a, (int)1, (int)0);
    auto [d, x, y] = gcd(b, a % b);
    return make_tuple(d, y, x - (a / b) * y);
}
 
bool diophantine(int a, int b, int c, int& x, int& y, int& d) {
    tie(d, x, y) = gcd(a * sign(a), b * sign(b));
    if(c % d) return false;
    x = x * sign(a) * (c / d);
    y = y * sign(b) * (c / d);
    return true;
}
 
void shift(int a, int b, int& x, int& y, int k) {
    x += k * b; 
    y -= k * a;
}
 
void enumerate(int a, int b, int c, int x1, int x2) {
    int y1 = (c - a * x1) / b;
    int y2 = (c - a * x2) / b;
    for(int x = x1, y = y1; x <= x2; x += b, y -= a) {
        cout << x << ' ' << y << endl;
    }
}
 
int equation_solver(int a, int b, int c, int minx = infmin, int maxx = infmax, int miny = infmin, int maxy = infmax) {
    if(a == 0 and b == 0) { //degeneracy
        if(c) return 0;
        return (maxx - minx + 1) * (maxy - miny + 1);
    }
    int x, y, d;
    if(!diophantine(a, b, c, x, y, d)) return 0;
    a /= d, b /= d;
    array<int, 2> left, right;
    shift(a, b, x, y, (minx - x) / b);
    if(x < minx) shift(a, b, x, y, sign(b));
    if(x > maxx) return 0;
    left[0] = x;
    shift(a, b, x, y, (maxx - x) / b);
    if(x > maxx) shift(a, b, x, y, -sign(b));
    right[0] = x;
    shift(a, b, x, y, -(miny - y) / a);
    if(y < miny) shift(a, b, x, y, -sign(a));
    if(y > maxy) return 0;
    left[1] = x;
    shift(a, b, x, y, -(maxy - y) / a);
    if(y > maxy) shift(a, b, x, y, sign(a));
    right[1] = x;
    if(left[1] > right[1]) swap(left[1], right[1]);
    int lo = max(left[0], left[1]);
    int hi = min(right[0], right[1]);
    if(lo > hi) return 0;
    //enumerate(a, b, c, lo, hi);
    return (hi - lo) / (b * sign(b)) + 1;
}
 
void hike() {
    int a, b, c; cin >> a >> b >> c;
    int minx, maxx, miny, maxy; cin >> minx >> maxx >> miny >> maxy;
    cout << equation_solver(a, b, -c, minx, maxx, miny, maxy) << endl;
}
 
signed main() {
    int t = 1; //cin >> t;
    while(t--) hike();
    return 0;
}//farewell, until we meet again..
