struct fenwick {
  int n;
  vector<int> bit;
  fenwick() = default;
  fenwick(int n): n(n) {
    bit.assign(n + 1, 0);
  }
  fenwick(vector<int>& a): fenwick(n) {
    for(int i = 1; i <= n; ++i) update(i, a[i - 1]);
  }
  int sum(int i) {
    int result = 0;
    for(int x = i; x; x -= x & -x) result += bit[x];
    return result;
  }
  int sum(int lo, int hi) {
    return sum(hi) - sum(lo - 1);
  }
  void update(int i, int delta) {
    for(int x = i; x <= n; x += x & -x) bit[x] += delta;
  }
  int read(int i) {
    int value = bit[i];
    if(i) {
      int idx = i - (i & -i);
      i = i - 1;
      while(i != idx) {
        value -= bit[i];
        i -= i & -i;
      }
    }
    return value;
  }
  void set(int i, int value) {
    update(i, value - read(i));
  }
};
