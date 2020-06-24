//author: hitch_hiker42;
auto predecessor(vector<int>& a, int n) {
    stack<int> s;
    vector<int> prev(n);
    for(int i = 0; i < n; ++i) {
        while(!s.empty() and a[s.top() - 1] > a[i]) s.pop();
        prev[i] = s.empty() ? -1 : s.top();
        s.push(i + 1);
    }
    return move(prev);
} //farewell, until we meet again..
