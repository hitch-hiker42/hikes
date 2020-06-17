#define span(a) begin(a), end(a)
#define point array<int, 2>
#define segment array<point, 2>
#define cast(a) {a[0], a[1]}

bool operator == (const point p, const point q) {
    return (p[0] == q[0] and p[1] == q[1]);
}

class Solution {
public:
    int sign(int x) {
        return (x > 0) - (x < 0);
    }
    int orientation(point& o, point& p, point& q) {
        point x = {p[0] - o[0], p[1] - o[1]};
        point y = {q[0] - o[0], q[1] - o[1]};
        return sign(x[0] * y[1] - x[1] * y[0]);
    }
    bool member(int x, int lo, int hi) {
        return (x >= lo and x <= hi);
    }
    bool onseg(segment l, point p) { //assumes 'p' is collinear with 'l'
        point lo = {min(l[0][0], l[1][0]), min(l[0][1], l[1][1])};
        point hi = {max(l[0][0], l[1][0]), max(l[0][1], l[1][1])};
        return member(p[0], lo[0], hi[0]) and member(p[1], lo[1], hi[1]);
    }
    inline bool cw(point o, point p, point q) {
        return orientation(o, p, q) == -1;
    }
    inline bool ccw(point o, point p, point q) {
        return orientation(o, p, q) == 1;
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& geo) {
        int n = geo.size();
        if(n <= 3) return geo;
        sort(span(geo), [](vector<int>& p, vector<int>& q) {
            return p[0] < q[0] || (p[0] == q[0] and p[1] < q[1]); 
        });
        point p = cast(geo.front()), q = cast(geo.back());
        vector<vector<int>> top{cast(p)}, bottom{cast(p)};
        for(int i = 1; i < n; ++i) {
            if(i == n - 1 || cw(p, point(cast(geo[i])), q)) {
                int m = top.size();
                while(m >= 2 and !cw(point(cast(top[m - 2])), point(cast(top[m - 1])), point(cast(geo[i])))) {
                    top.pop_back();
                    m = top.size();
                }
                top.push_back(geo[i]);
            }
            if(i == n - 1 || ccw(p, point(cast(geo[i])), q)) {
                int m = bottom.size();
                while(m >= 2 and !ccw(point(cast(bottom[m - 2])), point(cast(bottom.back())), point(cast(geo[i])))) {
                    bottom.pop_back();
                    m = bottom.size();
                }
                bottom.push_back(geo[i]);
            }
        }
        vector<vector<int>> hull, offset;
        for(auto& x: top) hull.push_back(x);
        bottom.pop_back(); reverse(span(bottom)); bottom.pop_back();
        for(auto& x: bottom) hull.push_back(x);
        int i = 0;
        do {
            int next = (i + 1) % hull.size();
            segment l = {point(cast(hull[i])), point(cast(hull[next]))};
            for(auto& j: geo) {
                point x = point(cast(j));
                if(x == l[0] || x == l[1]) continue;
                if(!orientation(l[0], l[1], x) and onseg(l, x)) offset.push_back(j);
            }
            i = next;
        } while(i != 0);
        for(auto& i: offset) hull.push_back(i);
        return hull;
    }
};
