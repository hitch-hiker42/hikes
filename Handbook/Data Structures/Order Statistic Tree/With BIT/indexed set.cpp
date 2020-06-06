//author: hitch_hiker42;
typedef struct fenwick {
    int n;
    vector<int> bit;
    fenwick(int n) {
        this -> n = n;
        bit.assign(n + 1, 0);
    }
    int sum(int i) {
        int result = 0;
        while(i) result += bit[i], i -= i & -i;
        return result;
    }
    int sum(int lo, int hi) {
        return sum(hi) - sum(lo - 1);
    }
    void update(int i, int delta) {
        while(i <= n) bit[i] += delta, i += i & -i;
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
        if(read(i) == 1) return;
        update(i, 1);
    }
    void erase(int i) {
        if(read(i) == 0) return;
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
        if(k > sum(n)) return -1;
        int run = 0, idx = 0;
        for(int i = log2(n); ~i; --i) {
            if(idx + (1 << i) < n and run + bit[idx + (1 << i)] < k) {
                run += bit[idx + (1 << i)];
                idx += 1 << i;
            }
        }
        return idx + 1;
    }
    int prev(int x) {
        return order_statistic(rank(x) - 1);
    }
    int next(int x) {
        return order_statistic(rank(x) + 1);
    }
} indexed_set; //farewell, until we meet again..
