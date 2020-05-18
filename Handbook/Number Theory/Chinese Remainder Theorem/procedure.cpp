//author: hitch_hiker42;
auto gcd(int a, int b) {
    if(!b) return make_tuple(a, (int)1, (int)0);
    auto [d, x, y] = gcd(b, a % b);
    return make_tuple(d, y, x - (a / b) * y);
}

int crt(const vector<array<int, 2>>& a, int n) {
    int result = 0;
    for(auto& i: a) {
        int r = i[0], m = i[1], k = n / m;
        int x = get<1>(gcd(k, m));
        result += ((x * k) % n * r) % n;
    }
    return (result + n) % n;
} //farewell, until we meet again..
