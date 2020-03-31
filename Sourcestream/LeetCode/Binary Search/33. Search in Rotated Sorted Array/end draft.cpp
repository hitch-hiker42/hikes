//author: hitch_hiker42;
struct Solution {
    int search(vector<int>& a, int target) {
        int n = (int)a.size(), lo = 0, hi = n - 1, m;
        if(!n) return -1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(a[mid] > a.back()) {
                lo = mid + 1;
            } else {
                m = mid;
                hi = mid - 1; 
            }
        }
        target > a.back() ? (lo = 0, hi = m - 1) : (lo = m, hi = n - 1);
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(a[mid] == target) return mid;
            if(a[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return - 1;
    }
}; //farewell.. until we meet again;
