struct Solution {
    int search(vector<int>& a, int target) {
        int n = (int)a.size(), lo = 0, hi = n - 1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            //return if the target is at median;
            if(a[mid] == target) return mid;
            //determine at which half relative to the pivot point does the median lies:
            if(a[mid] > a.back()) { //at left half;
                //determine where the target lies relative to the median;
                if(target > a.back()) { //target is in the left half too;
                    if(a[mid] < target) { //case 1: above median;
                        lo = mid + 1;
                    } else { //case 2: below median;
                        assert(a[mid] > target);
                        hi = mid - 1;
                    }
                } else { //case 3: target is in the right half (below median);
                    assert(a[mid] > target);
                    lo = mid + 1;
                }
            } else { //at right half;
                if(target <= a.back()) { //target is in the right half too;
                    if(a[mid] < target) { //case 1: above median;
                        lo = mid + 1;
                    } else { //case 2: below median;
                        assert(a[mid] > target);
                        hi = mid - 1;
                    }
                } else { //case 3: target is in the left half (above median);
                    assert(a[mid] < target);
                    hi = mid - 1;
                }
            }
        }
        //exit condition (lo > hi): target not found:
        return -1;
    }
};
