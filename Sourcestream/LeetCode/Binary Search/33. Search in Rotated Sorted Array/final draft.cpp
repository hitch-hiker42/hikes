struct Solution {
    int search(vector<int>& a, int target) {
        int n = (int)a.size(), lo = 0, hi = n - 1, m;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(a[mid] > a.back()) {
                lo = mid + 1;
            } else {
                m = mid;
                hi = mid - 1; 
            }
        }
        lo = 0, hi = n - 1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(a[(mid + m) % n] == target) return (mid + m) % n;
            if(a[(mid + m) % n] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return - 1;
    }
};
