//author: hitch_hiker42;
struct fenwick {
    int n, m;
    matrix bit;
    fenwick(int n, int m) {
        this -> n = n;
        this -> m = m;
        bit.assign(n + 1, vector<int>(m + 1, 0));
    }
    int query(array<int, 2> i) {
        int result = 0;
        for(int x = i[0]; x; x -= x & -x) {
            for(int y = i[1]; y; y -= y & -y) result += bit[x][y];
        }
        return result;
    }
    int query(array<int, 2> lo, array<int, 2> hi) {
        int a = query(hi), b = query({lo[0] - 1, hi[1]});
        int c = query({hi[0], lo[1] - 1}), d = query({lo[0] - 1, lo[1] - 1});
        return a + d - (b + c);
    }
    void update(array<int, 2> i, int delta) {
        for(int x = i[0]; x <= n; x += x & -x) {
            for(int y = i[1]; y <= m; y += y & -y) bit[x][y] += delta;
        }
    }
    void process();
}; //farewell, until we meet again..
