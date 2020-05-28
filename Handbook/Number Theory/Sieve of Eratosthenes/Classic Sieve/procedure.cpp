//author: hitch_hiker42;
#define int int64_t
constexpr int lim = 1000'001; //10'000'001, 100'000'001

//Vanilla:
auto sieve(int n) { //suitable for small 'n', yet doesn't dissapoint till 10^7
    vector<char> p(lim, true);
    p[0] = p[1] = false;
    for(int i = 4; i < n; i += 2) p[i] = false;
    for(int i = 3; i < n / i; i += 2) if(p[i]) {
        for(int j = i * i, k = i << 1; j <= n; j += k) p[j] = false;
    }
    vector<int> prime;
    for(int i = 2; i <= n; ++i) if(p[i]) prime.emplace_back(i);
    return move(prime);
}

//With bit-level compression:
auto sieve(int n) { //Variant I: serves for 'n' as large as 10^8 (in a way, keeps the best of the other two)
    vector<bool> p(lim, true); //the boolean type is the only difference
    p[0] = p[1] = false;
    for(int i = 4; i < n; i += 2) p[i] = false;
    for(int i = 3; i < n / i; i += 2) if(p[i]) {
        for(int j = i * i, k = i << 1; j <= n; j += k) p[j] = false;
    }
    vector<int> prime;
    for(int i = 2; i <= n; ++i) if(p[i]) prime.emplace_back(i);
    return move(prime);
}

//Variant II:
auto sieve(int n) { //Variant II: works well for sufficiently large 'n' (about 10^7), but not larger
    bitset<lim> p; p.set(); //again, only difference is in the container-type
    p[0] = p[1] = 0;
    for(int i = 4; i <= n; i += 2) p.reset(i);
    for(int i = 3; i <= n / i; i += 2) if(p[i]) {
        for(int j = i * i, k = i << 1; j <= n; j += k) p.reset(j);
    }
    vector<int> prime;
    for(int i = 2; i <= n; ++i) if(p[i]) prime.emplace_back(i);
    return move(prime);
} //farewell, until we meet again..
