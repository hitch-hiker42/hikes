struct segtree {
  int n;
  static inline int size = 1, id = 0;
  vector<int> t;
  segtree() = default;
  segtree(int n): n(n) {
    while(size < n) size <<= 1;
    t.assign(size << 1, 0);
  }
  int f(int x, int y) {
    return max(x, y);
  }
  void build(vector<int>& a, int x = 0, int l = 0, int r = size) {
    if(r - l == 1) {
      if(l < n) t[x] = a[l];
      return;
    }
    int m = l + r >> 1;
    build(a, 2 * x + 1, l, m);
    build(a, 2 * x + 2, m, r);
    t[x] = f(t[2 * x + 1], t[2 * x + 2]);
  }
  int query(int lo, int hi, int x = 0, int l = 0, int r = size) {
    if(lo >= r || l >= hi) return id;
    if(lo <= l and r <= hi) return t[x];
    int m = l + r >> 1;
    return f(query(lo, hi, 2 * x + 1, l, m), query(lo, hi, 2 * x + 2, m, r));
  }
  void update(int i, int v, int x = 0, int l = 0, int r = size) {
    if(r - l == 1) return void(t[x] = v);
    int m = l + r >> 1;
    if(i < m) {
      update(i, v, 2 * x + 1, l, m);
    } else {
      update(i, v, 2 * x + 2, m, r);
    }
    t[x] = f(t[2 * x + 1], t[2 * x + 2]);
  }
};
