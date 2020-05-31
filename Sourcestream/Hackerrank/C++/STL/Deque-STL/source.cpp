//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
struct window {
    deque<int> q;
    void push(int element) {
        while(!q.empty() and q.back() < element) q.pop_back();
        q.push_back(element);
    }
    int max() {
        return q.front();
    }
    void pop(int element) {
        if(!q.empty() and q.front() == element) q.pop_front();
    }
};

void hike() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int& i: a) cin >> i;
    window x;
    for(int i = 0; i < k; ++i) x.push(a[i]);
    cout << x.max() << " ";
    for(int i = k; i < n; ++i) {
        x.pop(a[i - k]); x.push(a[i]);
        cout << x.max() << " ";
    }
    cout << "\n";
}

signed main() {
    int t; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
