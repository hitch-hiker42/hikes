#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, i = 1;
    while(scanf("%d", &n), n) {
        int k = 0;
        for(int j = 0; j < n; ++j) {
            int x; cin >> x;
            if(!x) ++k;
        }
        cout << "Case " << i++ << ": " << n - (k << 1) << endl;
    }
    return 0;
}
