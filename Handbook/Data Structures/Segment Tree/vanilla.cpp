//author: hitch_hiker42;
#define parent(i) (i >> 1)
#define left(i) (i << 1)
#define right(i) (left(i) | 1)

struct segtree {
    int n, identity;
    vector<int> t;
    function<int(int, int)> op;
    segtree(vector<int> a, function<int(int, int)> bin, int id) {
        this -> n = a.size();
        this -> op = bin;
        identity = id;
        t.assign(n << 1, identity);
        for(int i = 0; i < n; ++i) t[n + i] = a[i];
        for(int i = n - 1; i; --i) {
            t[i] = op(t[left(i)], t[right(i)]);
        }
    }
    void update(int i, int delta) {
        for(t[i += n] = delta; i > 1; i >>= 1) t[parent(i)] = op(t[i], t[i ^ 1]);
    }
    int query(int lo, int hi) {
        int result = identity;
        for(lo += n, hi += n; lo < hi; lo >>= 1, hi >>= 1) {
            if (lo & 1) result = op(result, t[lo++]);
            if (hi & 1) result = op(result, t[--hi]);
        }
        return result;
    }
}; //farewell, until we meet again..
