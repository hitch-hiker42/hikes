#define block(i) (i / B)
constexpr int N = 300'001;
constexpr int A = 300'001;
constexpr int Q = 300'001;

int n, m, B, answer;
int a[N]; //original array;
int f[A]; //frequency array;
int ans[Q]; //answers to queries;
 
struct query {
  //indexing: 0-based;
  //extremes: inclusive;
  int lo, hi, idx, length;
  query() {}
  query(int lo, int hi, int idx): lo(lo), hi(hi), idx(idx) {}
  bool operator < (const query& q) {
    if(block(lo) != block(q.lo)) return block(lo) < block(q.lo);
    return (block(lo) & 1) ? (hi < q.hi) : (hi > q.hi);
  }
} q[Q];

void solver() {
  B = 2 * sqrt(n) + 0.5;
  auto insert = [&](int i) {
    f[a[i]]++;
    if(f[a[i]] == 1) answer++;
  };
  auto remove = [&](int i) {
    f[a[i]]--;
    if(f[a[i]] == 0) answer--;
  };
  sort(q, q + m);
  int l = 0, r = -1;
  for(int i = 0; i < m; ++i) {
    int lo = q[i].lo, hi = q[i].hi;
    while(lo < l) insert(--l);
    while(hi > r) insert(++r);
    while(lo > l) remove(l++);
    while(hi < r) remove(r--);
    ans[q[i].idx] = answer;
  }
}
