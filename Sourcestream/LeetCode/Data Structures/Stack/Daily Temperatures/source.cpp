//author: hitch_hiker42;
class Solution {
public:
    auto dailyTemperatures(vector<int>& a) {
        int n = a.size();
        vector<int> next(n);
        //maintain the monotone decreasing stack:
        stack<int> s;
        for(int i = 0; i < n; ++i) {
            while(!s.empty() and a[s.top()] < a[i]) {
                next[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return move(next);
    }
}; //farewell, until we meet again..
