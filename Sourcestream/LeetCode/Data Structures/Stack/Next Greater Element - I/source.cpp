//author: hitch_hiker42;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& x, vector<int>& a) {
        int n = a.size();
        vector<int> next(n, -1);
        map<int, int> hash;
        stack<int> s;
        for(int i = 0; i < n; ++i) {
            hash[a[i]] = i;
            while(!s.empty() and a[s.top()] < a[i]) {
                next[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        for(auto& i: x) if(~next[hash[i]]) i = a[next[hash[i]]]; else i = -1;
        return move(x);
    }
}; //farewell, until we meet again..
