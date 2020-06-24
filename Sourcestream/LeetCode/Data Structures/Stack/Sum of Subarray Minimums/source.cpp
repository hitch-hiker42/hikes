//author: hitch_hiker42;
class Solution {
public:
    int mod = 1000'000'007;
    int sumSubarrayMins(vector<int>& a) {
        int n = a.size();
        stack<int> s, t;
        vector<int> prev(n), next(n, n);
        for(int i = 0; i < n; ++i) {
            //predecessor:
            while(!s.empty() and a[s.top()] > a[i]) s.pop();
            prev[i] = s.empty() ? -1 : s.top();
            s.push(i);
            //successor:
            while(!t.empty() and a[t.top()] > a[i]) {
                next[t.top()] = i;
                t.pop();
            }
            t.push(i);
        }
        auto multiply = [&](int lhs, int rhs) {
            return ((long long)lhs * rhs) % mod;
        };
        auto add = [&](int lhs, int rhs) {
            return (lhs + rhs) % mod;
        };
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum = add(sum, multiply(a[i], multiply(i - prev[i], next[i] - i)));
        }
        return sum;
    }
}; //farewell, until we meet again..
