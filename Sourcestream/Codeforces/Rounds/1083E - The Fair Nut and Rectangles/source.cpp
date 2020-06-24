//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;
 
//solution:
#define int int64_t
#define span(a) begin(a), end(a)
 
struct line {
    int m, c;
    line() {}
    line(int m, int c): m(m), c(c) {}
    auto intersect(line l) {
        array<int, 2> x = {l.c - c, m - l.m};
        return x;
    }
    int f(int x) {
        return m * x + c;
    }
};
 
struct cht {
    deque<line> hull;
    cht() {}
    cht(line l) {
        hull.push_back(l);
    }
    void insert(line l) {
        while(hull.size() >= 2 and remove(l, end(hull)[-1], end(hull)[-2])) {
            hull.pop_back();
        }
        hull.push_back(l);
    }
    auto query(int x) {
        line result = {0, 0};
        int lo = 0, hi = hull.size() - 1;
        while(lo <= hi) {
            int mid1 = lo + (hi - lo) / 3;
            int mid2 = hi - (hi - lo) / 3;
            int y1 = hull[mid1].f(x), y2 = hull[mid2].f(x);
            if(y1 <= y2) result = hull[mid2], lo = mid1 + 1;
            else result = hull[mid1], hi = mid2 - 1;
        }
        return result;
    }
    bool remove(line prev, line now, line next) {
        auto x = prev.intersect(next), y = prev.intersect(now);
        return (long double)x[0] * y[1] <= (long double)y[0] * x[1];
    }
};
 
void hike() {
    int n; cin >> n;
    vector<array<int, 3>> r(n);
    for(auto& i: r) cin >> i[0] >> i[1] >> i[2];
    sort(span(r), [](const array<int, 3>& lhs, const array<int, 3>& rhs) {
        return lhs[0] < rhs[0];
    });
    vector<int> dp(n);
    dp[0] = r[0][0] * r[0][1] - r[0][2];
    cht env(line(-r[0][0], dp[0]));
    int maxima = dp[0];
    for(int i = 1; i < n; ++i) {
        auto l = env.query(r[i][1]);
        dp[i] = r[i][0] * r[i][1] - r[i][2] + l.f(r[i][1]) * (l.f(r[i][1]) >= 0);
        maxima = max(maxima, dp[i]);
        env.insert(line(-r[i][0], dp[i]));
    }
    cout << maxima << "\n";
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
