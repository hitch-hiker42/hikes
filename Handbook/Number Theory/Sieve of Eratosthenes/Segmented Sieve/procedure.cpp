//author: hitch_hiker42;
#define int long long int
constexpr int lim = 1000'001;

auto sieve(int n) {
    bitset<lim> p; p.set();
    for(int i = 4; i <= n; i += 2) p.reset(i);
    for(int i = 3; i <= n; i += 2) if(p[i]) {
        for(int j = i * i, k = i << 1; j <= n; j += k) p.reset(j);
    }
    vector<int> prime;
    for(int i = 2; i <= n; ++i) if(p[i]) prime.emplace_back(i);
    return move(prime);
}

auto segsieve(int lo, int hi) {
    vector<int> init = sieve((int)sqrtl(hi));
    int range = hi - lo + 1;
    bitset<lim> p; p.set();
    if(lo == 1) p.reset(0);
    for(int& i: init) {
        int m = lo + (i - lo % i) % i;
        if(m == i) m += i;
        for(int j = m; j <= hi; j += i) p.reset(j - lo);
    }
    vector<int> prime;
    for(int i = lo; i <= hi; ++i) if(p[i - lo]) prime.emplace_back(i);
    return move(prime);
} //farewell, until we meet again..
