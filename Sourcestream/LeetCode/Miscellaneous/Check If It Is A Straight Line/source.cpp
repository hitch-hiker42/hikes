//author: hitch_hiker42;
#define point vector<int>

class Solution {
public:
    int sign(int x) {
        return (x > 0) - (x < 0);
    }
    bool orientation(point& o, point& p, point& q) {
        point x = {p[0] - o[0], p[1] - o[1]};
        point y = {q[0] - o[0], q[1] - o[1]};
        return sign(x[0] * y[1] - y[0] * x[1]);
    }
    bool checkStraightLine(vector<point>& line) {
        for(int i = 0, n = (int)line.size(); i < n - 2; ++i) {
            if(orientation(line[i], line[i + 1], line[i + 2]) != 0) return false;
        }
        return true;
    }
}; //farewell, until we meet again..
