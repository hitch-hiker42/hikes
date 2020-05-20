//author: hitch_hiker42;
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

int lcm(int a, int b) {
    return (a * b) / get<0>(gcd(a, b));
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

int adjust(int x, int y, int z) {
    return (x - z) / y;
}

void enumerate(int a, int b, int c, int x1, int x2) {
    int y1 = (c - a * x1) / b;
    int y2 = (c - a * x2) / b;
    for(int x = x1, y = y1; x <= x2; x += b, y -= a) {
        cout << x << ' ' << y << endl;
    }
}

bool member(int x, int lo, int hi) {
    return (x >= lo and x <= hi);
}

int equation_solver(int a, int b, int c, int minx = infmin, int maxx = infmax, int miny = infmin, int maxy = infmax) {
    //degeneracy:
    if(a == 0 || b == 0) {
        if(a == b) {
            if(c) return 0;
            return (maxx - minx + 1) * (maxy - miny + 1);
        }
        if(a == 0) {
            if(c % b || !member(c / b, miny, maxy)) return 0;
            return (maxx - minx + 1);
        } else {
            assert(b == 0);
            if(c % a || !member(c / a, minx, maxx)) return 0;
            return (maxy - miny + 1);
        }
    }
    //non-trivial case:
    int x, y, d;
    if(!diophantine(a, b, c, x, y, d)) return 0;
    a /= d, b /= d;
    array<int, 2> left, right;
    shift(a, b, x, y, adjust(minx, b, x));
    if(x < minx) shift(a, b, x, y, sign(b));
    if(x > maxx) return 0;
    left[0] = x; //lower bound for x | x >= minx
    shift(a, b, x, y, adjust(maxx, b, x));
    if(x > maxx) shift(a, b, x, y, -sign(b));
    right[0] = x; //upper bound for x | x <= maxx
    shift(a, b, x, y, adjust(y, a, miny));
    if(y < miny) shift(a, b, x, y, -sign(a));
    if(y > maxy) return 0;
    left[1] = x; //lower bound for x | y >= miny
    shift(a, b, x, y, adjust(y, a, maxy));
    if(y > maxy) shift(a, b, x, y, sign(a));
    right[1] = x; //upper bound for x | y <= maxx
    if(left[1] > right[1]) swap(left[1], right[1]); //normalization | left[1] <= right[1]
    //find the intersection:
    int lo = max(left[0], left[1]); //lower bound for x | minx <= x <= maxx and miny <= y <= maxy
    int hi = min(right[0], right[1]); //upper bound for x | minx <= x <= maxx and miny <= y <= maxy
    if(lo > hi) return 0;
    //enumerate(a, b, c, lo, hi);
    return ((hi - lo) / (b * sign(b))) + 1;
} //farewell, until we meet again..
