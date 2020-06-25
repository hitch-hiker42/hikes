//author: hitch_hiker42;
class Solution {
public:
    #define span(a) begin(a), end(a)
    auto concate(vector<int>& x, vector<int> y) {
        move(span(y), back_inserter(x));
        return move(x);
    }
    auto nextGreaterElements(vector<int>& a) {
        int n = a.size(), m = n << 1;
        stack<int> s;
        a = concate(a, a);
        vector<int> next(n, -1);
        for(int i = 0; i < m; ++i) {
            while(!s.empty() and a[s.top()] < a[i]) {
                next[s.top() % n] = i % n;
                s.pop();
            }
            s.push(i);
        }
        for(auto& i: next) if(~i) i = a[i];
        return move(next);
    }
}; //farewell, until we meet again..
