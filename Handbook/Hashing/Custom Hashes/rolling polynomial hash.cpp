seed_seq seed {
  (uint64_t) chrono::duration_cast<chrono::nanoseconds>
  (chrono::high_resolution_clock::now().time_since_epoch()).count(),
  (uint64_t) __builtin_ia32_rdtsc(),
  (uint64_t) (uintptr_t) make_unique<char>().get()
};

mt19937_64 mersenne(seed);

int rng(int l, int r) {
  return uniform_int_distribution<int>(l, r)(mersenne);
}

constexpr int mod = 1e9 + 9;

auto power(int base, int exp) {
  int result = 1;
  while(exp) {
    if(exp & 1) (result *= base) %= mod;
    (base *= base) %= mod;
    exp >>= 1;
  }
  return result;
}

auto inverse(int i) {
  return power(i, mod - 2);
}

struct hash_t {
  string s;
  int n, p, invp;
  vector<int> hash, invhash, power, invpower;
  hash_t() = default;
  hash_t(string s): s(s), n(s.length()) {
    hash.assign(n, 0);
    invhash.assign(n, 0);
    power.assign(n, 1);
    invpower.assign(n, 1);
  }
  void init() {
    p = 2 * rng(13, 1e8) + 1;
    invp = inverse(p);
    for(int i = 0; i < n; ++i) {
      power[i] = (i ? power[i - 1] : (int)1) * p % mod;
      invpower[i] = (i ? invpower[i - 1] : (int)1) * invp % mod;
      hash[i] = (i ? hash[i - 1] : (int)0) + (s[i] - 'a' + 1) * power[i] % mod;
      invhash[i] = ((i ? invhash[i - 1] * p : (int)0)) + (s[i] - 'a' + 1);
      hash[i] %= mod;
      invhash[i] %= mod;
    }
  }
  int gethash(int l, int r) {
    int f = (hash[r] - (l ? hash[l - 1] : (int)0));
    if(f < 0) f += mod;
    f *= invpower[l];
    return f % mod;
  }
  int getinvhash(int l, int r) {
    int f = invhash[r] - (l ? invhash[l - 1] * power[r - l] % mod: (int)0);
    return (f % mod + mod) % mod;
  }
  bool compare(hash_t& h, int l1, int r1, int l2, int r2) {
    int n = r1 - l1 + 1, m = r2 - l2 + 1, lo = -1, hi = min(n, m);
    while(hi - lo > 1) {
      int mid = lo + hi >> 1;
      if(gethash(l1, l1 + mid) == h.gethash(l2, l2 + mid)) lo = mid;
      else hi = mid;
    }
    if(n == m) {
      if(hi == n) return false;
      return s[l1 + hi] < h.s[l2 + hi];
    } else {
      assert(false);
      if(hi == min(n, m)) return n < m;
      return s[l1 + hi] < h.s[l2 + hi];
    }
  }
};
