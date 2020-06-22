//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;
 
//solution:
#define int int64_t
 
struct line {
    int m, c; //slope-intercept form
    line() {};
    line(int m, int c): m(m), c(c) {}
    auto intersect(line l) { //returns the intersection point as a fraction
        array<int, 2> x = {l.c - c, m - l.m};
        return x;
    }
    auto f(int x) { //evaluates the line at a given point
        return m * x + c;
    }
};
 
struct cht { //semi-offline
    deque<line> hull;
    cht() {};
    cht(line l) { 
        hull.push_back(l);
    };
    void insert(line l) {
        while(hull.size() >= 2 and remove(end(hull)[-2], end(hull)[-1], l)) {
            hull.pop_back();
        }
        hull.push_back(l);
    }
    bool remove(line prev, line now, line next) {
        auto x = prev.intersect(next), y = prev.intersect(now);
        return (__int128)x[0] * y[1] <= (__int128)y[0] * x[1];
    }
    auto query(int x) { //ternary-search the required line
        line result(0, 0);
        int  lo = 0, hi = hull.size() - 1;
        while(lo <= hi) {
            int mid1 = lo + (hi - lo) / 3;
            int mid2 = hi - (hi - lo) / 3;
            int y1 = hull[mid1].f(x), y2 = hull[mid2].f(x);
            if(y1 <= y2) result = hull[mid1], hi = mid2 - 1;
            else result = hull[mid2], lo = mid1 + 1;
        }
        return result;
    }
};
 
void hike() {
    int n, c; cin >> n >> c;
    vector<int> h(n);
    for(int& i: h) cin >> i;
    int dp[n] = {};
    cht env(line(-2 * h[0], h[0] * h[0]));
    for(int i = 1; i < n; ++i) {
        line l = env.query(h[i]);
        dp[i] = l.f(h[i]) + h[i] * h[i] + c;
        env.insert(line(-2 * h[i], h[i] * h[i] + dp[i]));
    }
    cout << dp[n - 1] << "\n";
}
 
signed main() {
    int t = 1; //cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
