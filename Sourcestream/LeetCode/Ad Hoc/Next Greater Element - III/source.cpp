//author: hitch_hiker42;
class Solution {
public:
    #define inf numeric_limits<int>::max()
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if(!next_permutation(begin(s), end(s)) || stol(s) > inf) return -1;
        return stol(s);
    }
}; //farewell, until we meet again..
