//author: hitch_hiker42;
#define int long long int
constexpr int lim = 100'000'000;

auto sieve(int n) {
    vector<bool> p(n + 1, true);
    p[0] = p[1] = false;
    for(int i = 4; i <= n; i += 2) p[i] = false;
    for(int i = 9, j = 3 << 1; i <= n; i += j) p[i] = false;
    for(int i = 25, j = 0; i <= n; i += 5 * vector<int>{2, 4}[j], j = (j + 1) % 2) p[i] = false;
    int skip[] = {6, 4, 2, 4, 2, 4, 6, 2};
    map<int, int> wheel = {{1, 0}, {7, 1}, {11, 2}, {13, 3}, {17, 4}, {19, 5}, {23, 6}, {29, 7}};
    for(int i = 7, j = 1; i <= n / i; i += skip[j], j = (j + 1) % 8) {
        if(p[i]) {
            for(int k = i * i, l = wheel[i % 30]; k <= n; k += i * skip[l], l = (l + 1) % 8) {
                p[k] = false;
            }
        }
    }
    vector<int> prime{2, 3, 5};
    for(int i = 7, j = 1; i <= n; i += skip[j], j = (j + 1) % 8) {
        if(p[i]) prime.emplace_back(i);
    }
    return move(prime);
} //farewell, until we meet again..
