//author: hitch_hiker42;
#define int int64_t
#define line array<point, 2>

struct point {
    int x, y;
    point(): x(0), y(0) {}
    point(const int& x, const int& y): x(x), y(y) {}
    point operator + (const point& p) { //vector addition
        return point(x + p.x, y + p.y);
    }
    point operator - (const point& p) { //vector subtraction
        return point(x - p.x, y - p.y);
    }
    int operator * (const point& p) { //dot product
        return x * p.x + y * p.y;
    }
    int operator ^ (const point& p) { //cross product (magnitude)
        return x * p.y - p.x * y;
    }
};

//custom i/o for geometric objects:
istream& operator >> (istream& in, point& p) {
    return in >> p.x >> p.y;
}

istream& operator >> (istream& in, line& l) {
    return in >> l[0] >> l[1];
}

ostream& operator << (ostream& out, const point& p) {
    return out << "(" << p.x << ", " << p.y << ")";
}

ostream& operator << (ostream& out, const line& l) {
    return out << l[0] << " | " << l[1];
}

//procedures:
int sign(int x) {
    return (x > 0) - (x < 0);
}

bool member(int x, int lo, int hi) {
    return (x >= lo and x <= hi);
}

int direction(point o, point p, point q) {
    return sign((p - o) ^ (q - o));
}

bool onseg(line l, point p) {
    array<int, 2> lo = {min(l[0].x, l[1].x), min(l[0].y, l[1].y)};
    array<int, 2> hi = {max(l[0].x, l[1].x), max(l[0].y, l[1].y)};
    return member(p.x , lo[0], hi[0]) and member(p.y, lo[1], hi[1]);
}

bool intersect(line l, line m) {
    array<int, 4> d;
    d[0] = direction(l[0], l[1], m[0]);
    d[1] = direction(l[0], l[1], m[1]);
    d[2] = direction(m[0], m[1], l[0]);
    d[3] = direction(m[0], m[1], l[1]);
    if((d[0] * d[1]) == -1 || (d[2] * d[3] == -1)) return true;
    if(d[0] == 0 and onseg(l, m[0])) return true;
    if(d[1] == 0 and onseg(l, m[1])) return true;
    if(d[2] == 0 and onseg(m, l[0])) return true;
    if(d[3] == 0 and onseg(m, l[1])) return true;
    return false;
} //farewell, until we meet again..
