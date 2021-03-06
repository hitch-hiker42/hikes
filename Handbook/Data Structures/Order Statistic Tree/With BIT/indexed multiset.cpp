//author: hitch_hiker42;
typedef struct fenwick {
    int n;
    vector<int> bit;
    fenwick() = default;
    fenwick(int n) {
        this -> n = n;
        bit.assign(n + 1, 0);
    }
    int sum(int i) {
        int result = 0;
        for(int x = i; x; x -= x & -x) result += bit[x];
        return result;
    }
    int sum(int lo, int hi) {
        return sum(hi) - sum(lo - 1);
    }
    void update(int i, int delta) {
        for(int x = i; x <= n; x += x & -x) bit[x] += delta;
    }
    int read(int i) {
        int value = bit[i];
        if(i) {
            int idx = i - (i & -i);
            i = i - 1;
            while(i != idx) {
                value -= bit[i];
                i -= i & -i;
            }
        }
        return value;
    }
    void insert(int i) {
        update(i, 1);
    }
    void erase(int i) {
        update(i, -1);
    }
    bool empty() {
        if(sum(n)) return false;
        return true;
    }
    int rank(int i) {
        return sum(i);
    }
    int order_statistic(int k) {
        int run = 0, idx = 0;
        for(int i = log2(n); ~i; --i) {
            if(idx + (1 << i) < n and run + bit[idx + (1 << i)] < k) {
                run += bit[idx + (1 << i)];
                idx += (1 << i);
            }
        }
        return idx + 1;
    }
} indexed_multiset; //farewell, until we meet again..
