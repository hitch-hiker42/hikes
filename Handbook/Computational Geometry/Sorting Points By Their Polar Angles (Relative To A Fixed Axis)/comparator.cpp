//author: hitch_hiker42;
bool comparator(const point& p, const point& q) {
    if(p.y * q.y < 0) return p.y > 0;
    return direction(point(0, 0), p, q) < 0;
} //farewell, until we meet again..
