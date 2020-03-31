//author: bitch_biker42;
struct Solution {
    int search(vector<int>& a, int target) {
        #define span(v) begin(v), end(v)
        constexpr int infinity = numeric_limits<int>::max();
        auto skip_left = [&](int x) { return x > a.back() ? -infinity : x; };
        auto skip_right = [&](int x) { return x <= a.back() ? infinity : x; };
        auto adjust = [&](int x) { return target <= a.back() ? skip_left(x) : skip_right(x); };
        auto predicate = [&](int lhs, int rhs) { return adjust(lhs) < adjust(rhs); };
        auto it = lower_bound(span(a), target, predicate);
        return it != end(a) && *it == target ? distance(begin(a), it) : -1;
        #undef span(v)
    }
}; //on fire, bitches!
