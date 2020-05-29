//author: hitch_hiker42;
#define span(a) begin(a), end(a)
constexpr int lim = 100'000'000;
constexpr int s = 500'000; //10000, 100'000

//basis: {2, 3, 5, 7};
int w[] = {2, 6, 30, 210}; //circumferences
vector<int> skip[] = {{2}, {4, 2}, {6, 4, 2, 4, 2, 4, 6, 2}, {10, 2, 4, 2, 4, 6, 2, 6, 4, 2, 4, 6, 6, 2, 6, 4, 2, 6, 4, 6, 8, 4, 2, 4, 2, 4, 8, 6, 4, 6, 2, 4, 6, 2, 6, 6, 4, 2, 4, 6, 2, 6, 4, 2, 4, 2, 10, 2}}; //skiplists
vector<int> cycle[] = {{1, 3}, {1, 5, 7}, {1, 7, 11, 13, 17, 19, 23, 29, 31}, {1, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 121, 127, 131, 137, 139, 143, 149, 151, 157, 163, 167, 169, 173, 179, 181, 187, 191, 193, 197, 199, 209, 211}}; //search spaces
map<int, int> wheel[] = {{{1, 0}}, {{1, 0}, {5, 1}}, {{1, 0}, {7, 1}, {11, 2}, {13, 3}, {17, 4}, {19, 5}, {23, 6}, {29, 7}}, {{1, 0}, {11, 1}, {13, 2}, {17, 3}, {19, 4}, {23, 5}, {29, 6}, {31, 7}, {37, 8}, {41, 9}, {43, 10}, {47, 11}, {53, 12}, {59, 13}, {61, 14}, {67, 15}, {71, 16}, {73, 17}, {79, 18}, {83, 19}, {89, 20}, {97, 21}, {101, 22}, {103, 23}, {107, 24}, {109, 25}, {113, 26}, {121, 27}, {127, 28}, {131, 29}, {137, 30}, {139, 31}, {143, 32}, {149, 33}, {151, 34}, {157, 35}, {163, 36}, {167, 37}, {169, 38}, {173, 39}, {179, 40}, {181, 41}, {187, 42}, {191, 43}, {193, 44}, {197, 45}, {199, 46}, {209, 47}}}; //hashes
vector<int> seek[4];

void seeker() {
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < w[i]; ++j) seek[i].emplace_back(*lower_bound(span(cycle[i]), j));
    }
}

inline auto adjust(int i, int x, int ring) {
    //returns the first multiple of i that is at least x and in the wheel
    int m = max(i * i, x + (i - x % i) % i);
    int k = m / i, r = k % w[ring];
    int s = seek[ring][r];
    if(r == s) return m;
    return m += (s - r) * i;
};

auto sieve(int n) {
    vector<bool> p(n + 1, true);
    p[0] = p[1] = false;
    for(int i = 11, j = wheel[3][i % w[3]]; i <= n / i; i += skip[3][j], j = (j + 1) % 48) {
        if(p[i]) {
            for(int k = adjust(i, i * i, 3), l = wheel[3][(k / i) % w[3]]; k <= n; k += i * skip[3][l], l = (l + 1) % 48) {
                p[k] = false;
            }
        }
    }
    vector<int> prime;
    for(int i = 11, j = wheel[3][i % w[3]]; i <= n; i += skip[3][j], j = (j + 1) % 48) {
        if(p[i]) prime.emplace_back(i);
    }
    return move(prime);
}

auto segsieve(int n) {
    const int base = (int)sqrtl(n);
    vector<int> init = sieve(base), prime = {2, 3, 5, 7};
    for(int& i: init) prime.emplace_back(i);
    bool block[s]; //bitset<s> block;
    for(int k = 0; k * s <= n; ++k) {
        int lo = max(base + 1, k * s), hi = min(k * s + s - 1, n);
        memset(block, true, sizeof block); //block.set();
        for(int& i: init) {
            int m = adjust(i, lo, 3), k = wheel[3][(m / i) % w[3]];
            for(int j = m; j <= hi; j += i * skip[3][k], k = (k + 1) % 48) block[j - lo] = false;
        }
        int r = lo % w[3], s = seek[3][r], start = lo;
        if(r != s) start += (s - r);
        for(int i = start, j = wheel[3][i % w[3]]; i <= hi; i += skip[3][j], j = (j + 1) % 48) if(block[i - lo]) prime.emplace_back(i);
    }
    return move(prime);
} //farewell, until we meet again..
