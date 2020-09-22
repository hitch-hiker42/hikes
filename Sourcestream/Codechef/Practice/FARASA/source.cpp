//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int int64_t
#define span(a) begin(a), end(a)
using point = complex<double>;
constexpr double pi = acos(-1);

void fft(vector<point>& a, bool invert) {
  int n = (int)a.size();
  if(n == 1) return;
  vector<point> a0(n / 2), a1(n / 2);
  for(int i = 0; 2 * i < n; i++) {
    a0[i] = a[2 * i];
    a1[i] = a[2 * i + 1];
  }
  fft(a0, invert);
  fft(a1, invert);
  double ang = 2 * pi / n * (invert ? -1 : 1);
  point w(1), wn(cos(ang), sin(ang));
  for(int i = 0; 2 * i < n; i++) {
    a[i] = a0[i] + w * a1[i];
    a[i + n / 2] = a0[i] - w * a1[i];
    if(invert) {
      a[i] /= 2;
      a[i + n / 2] /= 2;
    }
    w *= wn;
  }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
  vector<point> fa(span(a)), fb(span(b));
  int n = 1;
  while(n < a.size() + b.size()) n <<= 1;
  fa.resize(n);
  fb.resize(n);
  fft(fa, false);
  fft(fb, false);
  for(int i = 0; i < n; i++) fa[i] *= fb[i];
  fft(fa, true);
  n = a.size() + b.size() - 1;
  vector<int> result(n);
  for(int i = 0; i < n; i++) result[i] = round(fa[i].real());
  return move(result);
}

void hike() {
  int n, sum = 0; cin >> n;
  vector<int> a(n);
  for(int& i: a) cin >> i, sum += i;
  if(n <= 2000) {
    set<int> s;
    for(int i = 0; i < n; ++i) {
      int sum = 0;
      for(int j = i; j < n; ++j) {
        sum += a[j];
        s.insert(sum);
      }
    }
    cout << s.size() - 1 << "\n";
  } else if(n <= 2e4 and sum <= 1e6) {
    int count[(int)1e6 + 1] = {};
    for(int i = 0; i < n; ++i) {
      int sum = 0;
      for(int j = i; j < n; ++j) {
        sum += a[j];
        count[sum] = 1;
      }
    }
    int s = 0;
    for(int i = 0; i <= 1e6; ++i) s += count[i];
    cout << s - 1 << "\n";
  } else {
    vector<int> p = a, x(sum + 1), y(sum + 1);
    x[p[0]] = y[sum] = y[sum - p[0]] = 1;
    for(int i = 1; i < n; ++i) {
      p[i] += p[i - 1];
      x[p[i]] = y[sum - p[i]] = 1;
    }
    auto z = multiply(x, y);
    int s = 0;
    for(int i = sum + 1, m = z.size(); i < m; ++i) s += (z[i] > 0);
    cout << s - 1 << "\n";
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1; //cin >> t;
  while(t--) hike();
  return 0;
} //farewell, until we meet again..
