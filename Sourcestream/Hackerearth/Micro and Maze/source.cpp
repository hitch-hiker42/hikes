//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define matrix vector<vector<int>>
vector<pair<int, int>> moves = {{0, -1}, {1, 0}, {-1, 0}, {0, 1}}; //{North, East, West, South}

auto valid(int i, int j, int n, int m) {
    if(i < 0 || i >= n) return false;
    if(j < 0 || j >= m) return false;
    return true;
} 

auto dfs(int i, int j, int n, int m, matrix& grid, matrix& visited) {
    visited[i][j] = true;
    if(!grid[i][j]) return false;
    if(i == n - 1 and j == m - 1) return true;
    bool test = false;
    for(auto& [x, y]: moves) {
        int u = i + x, v = j + y;
        if(valid(u, v, n, m) and !visited[u][v]) test |= dfs(u, v, n, m, grid,visited);
    }
    return test;
}

void hike() {
    int n, m; cin >> n >> m;
    matrix grid = matrix(n, vector<int>(m));
    for(auto& i: grid) for(int& j: i) cin >> j;
    matrix visited = matrix(n, vector<int>(m));
    cout << vector<string>{"No\n", "Yes"}[dfs(0, 0, n, m, grid, visited)];
}

signed main() {
    int t = 1; //cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
