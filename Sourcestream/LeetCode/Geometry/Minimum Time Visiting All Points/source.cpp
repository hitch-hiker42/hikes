//author: hitch_hiker42;
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& p) {
        int time = 0, n = (int)p.size();
        for(int i = 1; i < n; ++i) {
            time += max(abs(p[i - 1][0] - p[i][0]), abs(p[i - 1][1] - p[i][1]));
        }
        return time;
    }
}; //farewell, until we meet again..
