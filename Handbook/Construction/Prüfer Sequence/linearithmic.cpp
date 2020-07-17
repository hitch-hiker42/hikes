//author: hitch_hiker42;
//tree to code:
auto encode(vector<vector<int>>& adj, vector<int>& d, int n) {
    priority_queue<int, vector<int>, greater<int>> leaves;
    for(int i = 1; i <= n; ++i) {
        if(adj[i].size() == 1) leaves.push(i);
    }
    vector<int> code(n - 2);
    vector<bool> killed(n + 1);
    for(int i = 0; i < n - 2; ++i) {
        int leaf = leaves.top(), v;
        leaves.pop();
        killed[leaf] = true;
        for(auto& u: adj[leaf]) if(!killed[u]) v = u;
        code[i] = v;
        if(--d[v] == 1) leaves.push(v);
    }
    return move(code);
}

//code to tree:
auto decode(vector<int>& code, int n) {
    vector<int> d(n + 1, 1);
    for(int& i: code) d[i]++;
    priority_queue<int, vector<int>, greater<int>> leaves;
    for(int i = 1; i <= n; ++i) if(d[i] == 1) leaves.push(i);
    vector<pair<int, int>> edges;
    for(int& v: code) {
        int leaf = leaves.top();
        leaves.pop();
        edges.emplace_back(leaf, v);
        if(--d[v] == 1) leaves.push(v);
    }
    edges.emplace_back(leaves.top(), n);
    return move(edges);
} //farewell, until we meet again..
