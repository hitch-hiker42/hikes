//author: hitch_hiker42;
auto successor(vector<int>& a, int n) {
    stack<int> s;
    vector<int> next(n, -1);
    for(int i = 0; i < n; ++i) {
        while(!s.empty() and a[s.top() - 1] > a[i]) {
            nxtmin[s.top() - 1] = i + 1;
            s.pop();
        }
        s.push(i + 1);
    }
    return move(next);
} //farewell, until we meet again..
