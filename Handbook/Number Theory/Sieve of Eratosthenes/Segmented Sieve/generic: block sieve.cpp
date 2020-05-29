//author: hitch_hiker42;
#define int long long int
constexpr int lim = 1'000'001;
constexpr int s = 10000; //100'000, 500'000

auto sieve(int n) {
    vector<bool> p(n + 1, true);
    p[0] = p[1] = false;
    for(int i = 4; i <= n; i += 2) p[i] = false;
    for(int i = 3; i <= n / i; i += 2) if(p[i]) {
        for(int j = i * i, k = i << 1; j <= n; j += k) p[j] = false;
    }
    vector<int> prime;
    for(int i = 2; i <= n; ++i) if(p[i]) prime.emplace_back(i);
    return move(prime);
}

auto segsieve(int n) {
    vector<int> init = sieve((int)sqrtl(n)), prime;
    bool block[s]; //bitset<s> block;
    auto sift = [&](int lo, int hi) {
        memset(block, true, sizeof block); //block.set();
        for(int& i: init) {
            int m = lo + (i - lo % i) % i;
            if(m == i) m += i;
            for(int j = m; j <= hi; j += i) block[j - lo] = false;
        }
        if(lo == 1) block[0] = false;
        for(int i = lo; i <= hi; ++i) if(block[i - lo]) prime.emplace_back(i);
    };
    for(int k = 0; k * s <= n; ++k) {
        int i = max((int)1, k * s), j = min(i + s - 1, n);
        sift(i, j);
    }
    return move(prime);
} //farewell, until we meet again..
