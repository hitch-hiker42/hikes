//author: hitch_hiker42;
template<class T>
struct segtree {
    int n;
    T identity;
    vector<T> t;
    function<T(T, T)> op;
    segtree(vector<int> a, function<T(T, T)> bin, T id) {
        this -> n = a.size();
        this -> op = bin;
        identity = id;
        t.assign(n << 1, identity);
        for(int i = 0; i < n; ++i) t[n + i] = {a[i], 1};
        for(int i = n - 1; i; --i) {
            t[i] = op(t[left(i)], t[right(i)]);
        }
    }
    void update(int i, T delta) {
        for(t[i += n] = delta; i > 1; i >>= 1) t[parent(i)] = op(t[i], t[i ^ 1]);
    }
    auto query(int lo, int hi) {
        T result = identity;
        for(lo += n, hi += n; lo < hi; lo >>= 1, hi >>= 1) {
            if (lo & 1) result = op(result, t[lo++]);
            if (hi & 1) result = op(result, t[--hi]);
        }
        return result;
    }
}; //farewell, until we meet again..
