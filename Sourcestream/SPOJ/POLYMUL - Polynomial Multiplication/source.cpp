//author: hitch_hiker42;
#include "bits/stdc++.h"
using namespace std;

//solution:
#define int int64_t
#define span(a) begin(a), end(a)
using point = complex<double>;
constexpr double pi = acos(-1);

void fft(vector<point>& a, bool invert) {
    int n = (int)a.size();
    if(n == 1) return;
    vector<point> odd(n / 2), even(n / 2);
    for(int i = 0; 2 * i < n; i++) {
        even[i] = a[i << 1];
        odd[i] = a[(i << 1) | 1];
    }
    fft(even, invert);
    fft(odd, invert);
    double ang = 2 * pi / n * (invert ? -1 : 1);
    point w(1), wn(cos(ang), sin(ang));
    for(int i = 0; 2 * i < n; ++i) {
        a[i] = even[i] + w * odd[i];
        a[i + n/2] = even[i] - w * odd[i];
        if(invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<point> fa(span(a)), fb(span(b));
    int n = 1;
    while(n < (int)a.size() + (int)b.size()) n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);
    for(int i = 0; i < n; ++i) fa[i] *= fb[i];
    fft(fa, true);
    vector<int> result(n);
    for(int i = 0; i < n; ++i) result[i] = round(fa[i].real());
    return move(result);
}

void hike() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(auto& i: a) cin >> i;
    for(auto& i: b) cin >> i;
    auto c = multiply(a, b);
    for(int i = 0; i < ((n << 1) | 1); ++i) cout << c[i] << ' ';
    cout << endl;
}
 
signed main() {
    int t = 1; cin >> t;
    while(t--) hike();
} //farewell, until we meet again..
