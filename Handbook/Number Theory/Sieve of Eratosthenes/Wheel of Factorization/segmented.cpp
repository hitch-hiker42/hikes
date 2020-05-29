//author: hitch_hiker42;
#define int long long int
#define span(a) begin(a), end(a)
constexpr int lim = 100'000'000;
constexpr int s = 500'000; //10000, 100'000

//basis: {2, 3, 5};
int w[] = {2, 6, 30}; //circumferences
vector<int> skip[] = {{2}, {4, 2}, {6, 4, 2, 4, 2, 4, 6, 2}}; //skiplists
vector<int> cycle[] = {{1, 3}, {1, 5, 7}, {1, 7, 11, 13, 17, 19, 23, 29, 31}}; //search spaces
map<int, int> wheel[] = {{{1, 0}}, {{1, 0}, {5, 1}}, {{1, 0}, {7, 1}, {11, 2}, {13, 3}, {17, 4}, {19, 5}, {23, 6}, {29, 7}}}; //hashes

inline auto adjust(int i, int x, int ring) {
    //returns the first multiple of i that is at least x and in the wheel
    int m = max(i * i, x + (i - x % i) % i);
    int k = m / i, r = k % w[ring];
    int s = *lower_bound(span(cycle[ring]), r);
    if(r == s) return m;
    return m += (s - r) * i;
};

auto sieve(int n) {
    vector<bool> p(n + 1, true);
    p[0] = p[1] = false;
    for(int i = 4; i <= n; i += 2) p[i] = false;
    for(int i = adjust(3, 9, 0), j = wheel[0][(i / 3) % w[0]]; i <= n; i += 3 * skip[0][j]) p[i] = false;
    for(int i = adjust(5, 25, 1), j = wheel[1][(i / 5) % w[1]]; i <= n; i += 5 * skip[1][j], j = (j + 1) % 2) p[i] = false;
    for(int i = 7, j = wheel[2][i % w[2]]; i <= n / i; i += skip[2][j], j = (j + 1) % 8) {
        if(p[i]) {
            for(int k = adjust(i, i * i, 2), l = wheel[2][(k / i) % w[2]]; k <= n; k += i * skip[2][l], l = (l + 1) % 8) {
                p[k] = false;
            }
        }
    }
    vector<int> prime;
    for(int i = 7, j = wheel[2][i % w[2]]; i <= n; i += skip[2][j], j = (j + 1) % 8) {
        if(p[i]) prime.emplace_back(i);
    }
    return move(prime);
}

auto segsieve(int n) {
    const int base = (int)sqrtl(n);
    vector<int> init = sieve(base), prime = {2, 3, 5};
    for(int& i: init) prime.emplace_back(i);
    bool block[s];
    for(int k = 0; k * s <= n; ++k) {
        int lo = max(base + 1, k * s), hi = min(k * s + s - 1, n);
        memset(block, true, sizeof block);
        for(int i = max(4LL, lo + (2 - lo % 2) % 2); i <= hi; i += 2) block[i - lo] = false;
        for(int i = adjust(3LL, lo, 0), j = wheel[0][(i / 3) % w[0]]; i <= hi; i += 3 * skip[0][j]) block[i - lo] = false;
        for(int i = adjust(5LL, lo, 1), j = wheel[1][(i / 5) % w[1]]; i <= hi; i += 5 * skip[1][j], j = (j + 1) % 2) block[i - lo] = false;
        for(int& i: init) {
            int m = adjust(i, lo, 2), k = wheel[2][(m / i) % w[2]];
            for(int j = m; j <= hi; j += i * skip[2][k], k = (k + 1) % 8) block[j - lo] = false;
        }
        int r = lo % w[2], s = *lower_bound(span(cycle[2]), r), start = lo;
        if(r != s) start += (s - r);
        for(int i = start, j = wheel[2][i % w[2]]; i <= hi; i += skip[2][j], j = (j + 1) % 8) if(block[i - lo]) prime.emplace_back(i);
    }
    return move(prime);
} //farewell, until we meet again..
