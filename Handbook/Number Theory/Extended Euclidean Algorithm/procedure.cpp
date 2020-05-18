//author: hitch_hiker42;
auto gcd(int a, int b) {
    if(!b) return make_tuple(a, (int)1, (int)0);
    auto [d, x, y] = gcd(b, a % b);
    return make_tuple(d, y, x - (a / b) * y);
} //farewell, until we meet again..
