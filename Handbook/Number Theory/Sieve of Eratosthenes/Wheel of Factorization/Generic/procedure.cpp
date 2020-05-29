//author: hitch_hiker42;
#define span(a) begin(a), end(a)
constexpr int lim = 100'000'000;
constexpr int s = 500'000; //10000, 100'000
constexpr int mod = 500;

//wheel of factorization:
constexpr int b = 6; //can be extended on whim
int basis[b] = {2, 3, 5, 7, 11, 13}, w[b], cycle; //basis must be modified accordingly
vector<int> spokes[b], skip[b], wheel[b], seek[b];

void construct() {
    for(int j = 1; j <= b; ++j) {
        vector<int> base(begin(basis), begin(basis) + j);
        
        //circumference:
        w[j - 1] = accumulate(span(base), 1, multiplies<int>());

        //spokes:
        vector<bool> p(w[j - 1], true);
        p[0] = false;
        for(int& i: base) {
            p[i] = false;
            for(int k = i * i; k < w[j - 1]; k += i) p[k] = false;
        }
        for(int i = 1; i < w[j - 1]; ++i) if(p[i]) spokes[j - 1].emplace_back(i);

        //skiplists:
        for(int i = 1, z = (int)spokes[j - 1].size(); i < z; ++i) {
            skip[j - 1].emplace_back(spokes[j - 1][i] - spokes[j - 1][i - 1]);
        }
        skip[j - 1].emplace_back(2);

        //wheel hashes:
        wheel[j - 1].resize(w[j - 1]);
        for(int i = 0, z = (int)skip[j - 1].size(); i < z; ++i) {
            wheel[j - 1][spokes[j - 1][i]] = i;
        }
    }
    cycle = (int)skip[b - 1].size();
}

void seeker() {
    for(int i = 0; i < b; ++i) {
        for(int j = 0; j < w[i]; ++j) seek[i].emplace_back(*lower_bound(span(spokes[i]), j));
    }
}

inline auto adjust(int i, int x, int ring) {
    //returns the first multiple of i that is at least x and in the wheel
    int m = max(i * i, x + (i - x % i) % i);
    int k = m / i, r = k % w[ring];
    int s = seek[ring][r];
    if(r == s) return m;
    return m += (s - r) * i;
}

auto sieve(int n) {
    vector<bool> p(n + 1, true);
    p[0] = p[1] = false;
    for(int i = spokes[b - 1][1], j = wheel[b - 1][i % w[b - 1]]; i <= n / i; i += skip[b - 1][j], j = (j + 1) % cycle) {
        if(p[i]) {
            for(int k = adjust(i, i * i, b - 1), l = wheel[b - 1][(k / i) % w[b - 1]]; k <= n; k += i * skip[b - 1][l], l = (l + 1) % cycle) {
                p[k] = false;
            }
        }
    }
    vector<int> prime;
    for(int i = spokes[b - 1][1], j = wheel[b - 1][i % w[b - 1]]; i <= n; i += skip[b - 1][j], j = (j + 1) % cycle) {
        if(p[i]) prime.emplace_back(i);
    }
    return move(prime);
}

auto segsieve(int n) {
    const int base = (int)sqrt(n);
    vector<int> init = sieve(base), prime(basis, basis + b);
    for(int& i: init) prime.emplace_back(i);
    bool block[s]; //bitset<s> block;
    for(int k = 0; k * s <= n; ++k) {
        int lo = max(base + 1, k * s), hi = min(k * s + s - 1, n);
        memset(block, true, sizeof block); //block.set();
        for(int& i: init) {
            int m = adjust(i, lo, b - 1), k = wheel[b - 1][(m / i) % w[b - 1]];
            for(int j = m; j <= hi; j += i * skip[b - 1][k], k = (k + 1) % cycle) block[j - lo] = false;
        }
        int r = lo % w[b - 1], s = seek[b - 1][r], start = lo;
        if(r != s) start += (s - r);
        int count = 0;
        for(int i = start, j = wheel[b - 1][i % w[b - 1]]; i <= hi; i += skip[b - 1][j], j = (j + 1) % cycle) {
            if(block[i - lo]) prime.emplace_back(i);
        }
    }
    return move(prime);
} //farewell, until we meet again..
