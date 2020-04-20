//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

int md(int x, int y) {
    return int(abs(x) + abs(y));
}

bool valid(int x, int y) {
    if(md(x, y) & 1) return true;
    return false;
}

array<int, 2> transform(int x, int y, int a) {
    array<int, 2> t = {x, y};
    if(x & 1) t[0] += a; else t[1] += a;
    t[0] >>= 1, t[1] >>= 1;
    return t;
}

string recurse(int x, int y, string& path) {
    if(md(x, y) == 1) {
        if(x) {
            return path += "EW"[x == -1];
        } else {
            return path += "NS"[y == -1];
        }
    }
    array<int, 2> p = transform(x, y, -1);
    array<int, 2> q = transform(x, y, 1);
    if(valid(p[0], p[1])) {
        return recurse(p[0], p[1], path += "EN"[y & 1]);
    } else {
        return recurse(q[0], q[1], path += "WS"[y & 1]);
    }
}

void hike() {
    int x, y; cin >> x >> y;
    if(!valid(x, y)) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    string path = "";
    cout << recurse(x, y, path) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    for(int i = 1; i <= t; cout << "Case #" << i << ": ", hike(), ++i);
    return 0;
} //farewell, until we meet again..
