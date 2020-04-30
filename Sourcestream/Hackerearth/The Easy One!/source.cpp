//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define span(a) begin(a), end(a)
constexpr int mod = 1000'000'007;

auto power(int64_t base, int64_t exp, int m) {
    int64_t result = 1;
    while(exp) {
        if(exp & 1) (result *= base) %= m;
        (base *= base) %= m;
        exp >>= 1;
    }
    return result;
}

auto multiplicative_inverse(int n, int m) {
    return power(n, m - 2, m);
}

int64_t modular_permutation(int64_t n, deque<int64_t> f, int m) {
    int64_t result = 1; 
    f.push_front(n);
    deque<int64_t> p(f.size());
    partial_sum(span(f), begin(p), [&](const int64_t& x, const int64_t& y) {return x - y;});
    p.pop_back(); 
    f.pop_front();
    vector<int64_t> fin;
    for(int i = 0; i < p.size(); i++) {
        int64_t x = 1;
        for(int j = 0; j < f[i]; j++) (x *= p[i] - j) %= m;
        fin.push_back(x);
    }
    for(int i = 0; i < f.size(); i++) {
        int64_t k = 1;
        for(int j = 1; j <= f[i]; j++) (k *= j) %= m;
        fin.push_back(multiplicative_inverse(k, m));
    }
    for(const int64_t& i: fin) (result *= i) %= m;
    return result;
}

void hike() {
    string s; cin >> s;
    int64_t n(0); deque<int64_t> f;
    unordered_map<char, int64_t> freq;
    for(const char &i: s) freq[i]++;
    for(const auto &i: freq) f.push_back(i.second);
    n = accumulate(span(f), n);
    cout << modular_permutation(n, f, mod) << endl;
}

signed main() {
    int t; cin >> t;
    while(t--) hike();
} //farewell, until we meet again;
