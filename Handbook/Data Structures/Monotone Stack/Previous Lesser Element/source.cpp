//author: hitch_hiker42;
auto ple(vector<int>& a) {
    int n = a.size();
    vector<int> premin(n);
    stack<int> s;
    for(int i = 0; i < n; ++i) {
        while(!s.empty() and a[s.top() - 1] > a[i]) s.pop();
        premin[i] = s.empty() ? -1 : s.top();
        s.push(i + 1);
    }
    return move(premin);
} //farewell, until we meet again..
