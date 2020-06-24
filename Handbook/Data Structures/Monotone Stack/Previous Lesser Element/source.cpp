//author: hitch_hiker42;
auto ple(vector<int>& a) {
    int n = a.size();
    vector<int> premin(n);
    stack<int> s;
    for(int i = 0; i < n; ++i) {
        while(!s.empty() and a[s.top() - 1] > a[i]) s.pop();
        if(s.empty()) {
            premin[i] = -1;
            s.push(i + 1);
            continue;
        }
        premin[i] = s.top();
        s.push(i + 1);
    }
    return move(premin);
} //farewell, until we meet again..
