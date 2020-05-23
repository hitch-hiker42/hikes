//author: hitch_hiker42;
void visit(vector<int>& a) {
    for(int i = 1; i < (int)a.size(); ++i) cout << a[i] << ' ';
    cout << endl;
}

void hike() {
    int n; cin >> n;
    vector<int> m(n + 1, 2), a(n + 1, 0);
    for(int i = 1; i <= n; ++i) cin >> m[i];
    for(int j = 1; j; ++a[j]) {
        visit(a); j = n;
        while(a[j] == m[j] - 1) a[j] = 0, --j;
    }
} //farewell, until we meet again..
