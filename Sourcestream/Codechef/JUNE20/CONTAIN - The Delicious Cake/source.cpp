//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int int64_t
#define line array<point, 2>
#define polygon vector<point>
#define span(a) begin(a), end(a)

struct point {
    int x, y;
    point(): x(0), y(0) {}
    point(const int& x, const int& y): x(x), y(y) {}
    void swap(point& p) {
        std::swap(x, p.x);
        std::swap(y, p.y);
    }
    point operator + (const point& p) {
        return point(x + p.x, y + p.y);
    }
    point operator - (const point& p) {
        return point(x - p.x, y - p.y);
    }
    int operator * (const point& p) {
        return x * p.x + y * p.y;
    }
    int operator ^ (const point& p) {
        return x * p.y - p.x * y;
    }
    int norm() {
        return (*this) * (*this);
    }
    int norm(point& p) {
        return (*this - p) * (*this - p);
    }
};

istream& operator >> (istream& in, point& p) {
    return in >> p.x >> p.y;
}

ostream& operator << (ostream& out, const point& p) {
    return out << p.x << " " << p.y;
}

ostream& operator << (ostream& out, const line& l) {
    return out << l[0] << " | " << l[1];
}

int operator * (const point& p, const point& q) {
    return p.x * q.x + p.y * q.y;
}

int operator ^ (const point& p, const point& q) {
    return p.x * q.y - q.x * p.y;
}

bool operator < (const point& p, const point& q) {
    return p.y < q.y || (p.y == q.y and p.x < q.x);
}

bool operator == (const point& p, const point& q) {
    return p.x == q.x and p.y == q.y;
}

bool operator > (const point& p, const point& q) {
    return q < p;
}

int sign(int x) {
    return (x > 0) - (x < 0);
}

int cross(point o, point p, point q) {
    return (p - o) ^ (q - o);
}

int orientation(point o, point p, point q) {
    return sign(cross(o, p, q));
}

bool cw(point o, point p, point q) {
    return orientation(o, p, q) == -1;
}

bool ccw(point o, point p, point q) {
    return orientation(o, p, q) == 1;
}

bool member(int x, int lo, int hi) {
    return (x >= lo and x <= hi);
}

bool onseg(line l, point p) { //assumes 'p' is collinear with 'l'
    array<int, 2> lo = {min(l[0].x, l[1].x), min(l[0].y, l[1].y)};
    array<int, 2> hi = {max(l[0].x, l[1].x), max(l[0].y, l[1].y)};
    return member(p.x , lo[0], hi[0]) and member(p.y, lo[1], hi[1]);
}

bool inside(const polygon& layer, const point& p) {
    int n = layer.size();
    int direction = orientation(layer[n - 1], p, layer[0]);
    if(!direction) return false;
    for(int i = 0; i < n - 1; ++i) {
        int sense = orientation(layer[i], p, layer[i + 1]);
        if(sense == (-direction) || !sense) return false;
    }
    return true;
}

vector<bool> mark;

polygon graham_scan(vector<pair<point, int>>& geo) {
    if(geo.size() == 1) {
        auto pass = geo.front(); geo.clear();
        mark[pass.second] = false;
        return polygon(1, pass.first);
    }
    sort(span(geo), [](const pair<point, int>& p, const pair<point, int>& q) {
        return p.first.x < q.first.x || (p.first.x == q.first.x and p.first.y < q.first.y);
    });
    auto p = geo.front(), q = geo.back();
    vector<pair<point, int>> top{p}, bottom{p};
    for(int i = 1, n = (int)geo.size(); i < n; ++i) {
        if(i == n - 1 || cw(p.first, geo[i].first, q.first)) {
            while(top.size() >= 2 and !cw(prev(prev(end(top))) -> first, top.back().first, geo[i].first)) top.pop_back();
            top.push_back(geo[i]);
        }
        if(i == n - 1 || ccw(p.first, geo[i].first, q.first)) {
            while(bottom.size() >= 2 and !ccw(prev(prev(end(bottom))) -> first, bottom.back().first, geo[i].first)) bottom.pop_back();
            bottom.push_back(geo[i]);
        }
    }
    polygon hull;
    for(auto& [x, i]: top) hull.push_back(x), mark[i] = false;
    bottom.pop_back(); reverse(span(bottom)); bottom.pop_back();
    for(auto& [x, i]: bottom) hull.push_back(x), mark[i] = false;
    auto pass = geo; geo.clear();
    for(auto& [x, i]: pass) if(mark[i]) geo.emplace_back(x, i);
    pass.clear();
    int n = (int)hull.size(), i = 0;
    do {
        int next = (i + 1) % n;
        line l = {hull[i], hull[next]};
        for(auto& [x, j]: geo) if(mark[j] and !orientation(l[0], l[1], x) and onseg(l, x)) {
            mark[j] = false;
        }
        i = next;
    } while(i != 0);
    for(auto& [x, i]: geo) if(mark[i]) pass.emplace_back(x, i);
    geo.clear(); geo = pass;
    return hull;
}

void hike() {
    int n, q, i = 0; cin >> n >> q;
    mark.assign(n, true);
    vector<pair<point, int>> geo(n);
    for(auto& [p, j]: geo) cin >> p, j = i++;
    vector<polygon> ripple;
    while(!geo.empty()) {
        polygon hull = graham_scan(geo);
        ripple.push_back(hull);
    }
    int m = ripple.size();
    while(q--) {
        point p; cin >> p;
        int layers = 0;
        for(int i = 0; i < m; ++i) {
            if(inside(ripple[i], p)) layers = layers + 1;
            else break;
        }
        cout << layers << "\n";
    }
}

signed main() {
    int t; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
