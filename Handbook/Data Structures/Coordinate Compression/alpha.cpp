//author: hitch_hiker42;
void compress(vector<query>& a, int& m, map<int, int>& hash) {
    int n = a.size();
    vector<int> u, v;
    for(int i = 0; i < n; ++i) if(a[i].type != 'K') u.emplace_back(a[i].x);
    v = u; sort(span(v));
    m = numeric_limits<int>::min();
    for(int i = 0, j = 0; i < n; ++i) {
        if(a[i].type != 'K') {
            a[i].x = distance(begin(v), lower_bound(span(v), u[j])) + 1;
            hash[a[i].x] = u[j];
            m = max(m, a[i].x);
            j = j + 1;
        }
    }
} //farewell, until we meet again..
