struct segtree {
    using T = int; //node type
    using Q = int; //query type
    T identity = 0;
    T f(T lhs, T rhs) {
        return lhs + rhs;
    }
    int n, size;
    vector<T> tree;
    segtree() {}
    segtree(int n): n(n) {
        size = 1;
        while(size < n) size <<= 1;
        tree.assign(size << 1, identity);
    }
    Q query(int lo, int hi, int x, int l, int r) {
        if(l >= hi || lo >= r) return identity;
        if(l >= lo and r <= hi) return tree[x];
        int m = l + r >> 1;
        return f(query(lo, hi, 2 * x + 1, l, m), query(lo, hi, 2 * x + 2, m, r));
    }
    Q query(int lo, int hi) {
        return query(lo, hi, 0, 0, size);
    }
    void update(int i, int v, int x, int l, int r) {
        if(r - l == 1) {
            tree[x] = v;
            return;
        }
        int m = l + r >> 1;
        if(i < m) {
            update(i, v, 2 * x + 1, l, m);
        } else {
            update(i, v, 2 * x + 2, m, r);
        }
        tree[x] = f(tree[2 * x + 1], tree[2 * x + 2]);
    }
    void update(int i, int v) {
        update(i, v, 0, 0, size);
    }
};
