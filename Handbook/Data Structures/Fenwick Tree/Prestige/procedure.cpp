//author: hitch_hiker42;
struct fenwick {
    int n;
    vector<int> bit[3];
    fenwick(int n) {
        this -> n = n;
        bit[0].assign(n + 1, 0);
        bit[1].assign(n + 1, 0);
        bit[2].assign(n + 1, 0);
    }
    fenwick(vector<int>& a): fenwick(a.size()) {
        for(int i = 1; i <= n; ++i) updatep(i, a[i - 1], 2);
    }
    int queryp(int i, int key) {
        int result = 0;
        for(int x = i; x; x -= x & -x) result += bit[key][x];
        return result;
    }
    int query(int i) {
        int a = queryp(i, 0), b = queryp(i, 1);
        return a * i + b;
    }
    int query(int lo, int hi) {
        int offset = query(hi) - query(lo - 1);
        return queryp(hi, 2) - queryp(lo - 1, 2) + offset;
    }
    void updatep(int i, int delta, int key) {
        for(int x = i; x <= n; x += x & -x) bit[key][x] += delta;
    }
    void updater(int lo, int hi, int delta, int key) {
        updatep(lo, delta, key);
        updatep(hi + 1, -delta, key);
    }
    void update(int lo, int hi, int delta) {
        updater(lo, hi, delta, 0);
        updater(lo, hi, -(lo - 1) * delta, 1);
        updater(hi + 1, n, (hi - lo + 1) * delta, 1);
    }
    int read(int i) {
        int value = bit[2][i];
        if(i) {
            int idx = i - (i & -i);
            i = i - 1;
            while(i != idx) {
                value -= bit[2][i];
                i -= i & -i;
            }
        }
        return value;
    }
    void write(int i, int value) {
        updatep(i, value - read(i), 2);
    }
    int lower_bound(int k) {
        int run = 0, idx = 0;
        for(int i = log2(n); ~i; --i) {
            if(idx + (1 << i) < n and run + bit[2][idx + (1 << i)] < k) {
                run += bit[2][idx + (1 << i)];
                idx += (1 << i);
            }
        }
        return idx + 1;
    }
    void process(); //to be defined, for query processing..
}; //farewell, until we meet again..
