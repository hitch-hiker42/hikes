struct segtree {
  //two functions + and * are lazy - compatible,
  //if * is distributive over +: x * (a + b) = x * a + x * b,
  //where + is the query operation and * is the update operation..
  //also, remember to return identity of + from query() and assign t with
  //the same in the constructor, at last initialize lazy with the identity of *,
  //and set it to the same at the end of push();
  int n;
  static inline int size = 1;
  vector<int> t, lazy;
  segtree() = default;
  segtree(int n): n(n) {
    while(size < n) size <<= 1;
    t.assign(size << 1, 1e18);
    lazy.assign(size << 1, 0);
  }
  void push(int x) {
    t[2 * x + 1] += lazy[x];
    t[2 * x + 2] += lazy[x];
    lazy[2 * x + 1] += lazy[x];
    lazy[2 * x + 2] += lazy[x];
    lazy[x] = 0;
  }
  void build(vector<int>& a, int x = 0, int l = 0, int r = size) {
    if(r - l == 1) {
      if(l < n) return void(t[x] = a[l]);
      return;
    }
    int m = l + r >> 1;
    build(a, 2 * x + 1, l, m);
    build(a, 2 * x + 2, m, r);
    t[x] = min(t[2 * x + 1], t[2 * x + 2]);
  }
  int query(int lo, int hi, int x = 0, int l = 0, int r = size) {
    if(l >= hi || lo >= r) return 1e18;
    if(lo <= l and r <= hi) return t[x];
    push(x);
    int m = l + r >> 1;
    return min(query(lo, hi, 2 * x + 1, l, m), query(lo, hi, 2 * x + 2, m, r));
  }
  void update(int lo, int hi, int v, int x = 0, int l = 0, int r = size) {
    if(l >= hi || lo >= r) return;
    if(lo <= l and r <= hi) {
      t[x] += v, lazy[x] += v;
      return;
    }
    push(x);
    int m = l + r >> 1;
    update(lo, hi, v, 2 * x + 1, l, m);
    update(lo, hi, v, 2 * x + 2, m, r);
    t[x] = min(t[2 * x + 1], t[2 * x + 2]);
  }
};
