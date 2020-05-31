//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
struct window{
    stack<array<int, 2>> x, y;
    void push(int element) {
        int m = x.empty() ? element : std::max(x.top()[1], element);
        x.push({element, m});
    }
    void pop() {
        if(x.empty() and y.empty()) return;
        if(y.empty()) {
            while(!x.empty()) {
                auto z = x.top();
                int m = y.empty() ? z[0] : std::max(y.top()[1], z[0]);
                y.push({z[0], m});
                x.pop();
            }
        }
        y.pop();
    }
    int max() {
        if(x.empty() || y.empty()) {
            if(x.empty() and y.empty()) return 0;
            if(x.empty()) return y.top()[1];
            return x.top()[1];
        }
        return std::max(x.top()[1], y.top()[1]);
    }
};

void hike() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int& i: a) cin >> i;
    window q;
    for(int i = 0; i < k; ++i) q.push(a[i]);
    cout << q.max() << " ";
    for(int i = k; i < n; ++i) {
        q.push(a[i]); q.pop();
        cout << q.max() << " ";
    }
    cout << "\n";
}

signed main() {
    int t; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
