//author: hitch_hiker42;
#define int int64_t
constexpr int lim = 1000'001;

auto sieve(int n) {
    bitset<lim> p; p.set();
    p[0] = p[1] = 0;
    for(int i = 4; i <= n; i += 2) p.reset(i);
    for(int i = 3; i <= n / i; i += 2) if(p[i]) {
        for(int j = i * i, k = i << 1; j <= n; j += k) p.reset(j);
    }
    vector<int> prime;
    for(int i = 2; i <= n; ++i) if(p[i]) prime.emplace_back(i);
    return move(prime);
} //farewell, until we meet again..
