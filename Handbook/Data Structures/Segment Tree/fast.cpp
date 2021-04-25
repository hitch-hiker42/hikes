constexpr int mxn = 1e5;
int n, a[mxn], t[mxn << 1];

int f(int i, int j) {
  return max(i, j);
}

void build() {
  for(int i = 0; i < n; ++i) t[n + i] = a[i];
  for(int i = n - 1; i; --i) {
    t[i] = f(t[i << 1], t[(i << 1) | 1]);
  }
}
 
void update(int i, int delta) {
  for(t[i += n] = delta; i > 1; i >>= 1) {
    t[(i >> 1)] = max(t[i], t[i ^ 1]);
  }
}
 
int query(int lo, int hi) {
  int result = 0;
  for(lo += n, hi += n; lo < hi; lo >>= 1, hi >>= 1) {
    if (lo & 1) result = max(result, t[lo++]);
    if (hi & 1) result = max(result, t[--hi]);
  }
  return result;
}
