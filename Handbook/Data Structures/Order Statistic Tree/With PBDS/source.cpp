//author: hitch_hiker42;
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;

signed main() {
    indexed_set t, u;
    int x, k;
    t.insert(x); //insert a key into the container
    t.erase(x); //delete a key from the container
    t.order_of_key(x); //seek the rank of a key
    t.find_by_order(k); //find the k-th order statistic
    t.join(u); //merge u into t, provided that the two trees have the same type and no duplicate elements
    t.split(x, b); //elements with key less than or equal to x belong to t, and the rest belong to b after split
    t.lower_bound(x); //returns the iterator to the first element greater than or equal to x
    t.upper_bound(x); //returns the iterator to the first element greater than x
    return 0;
} //farewell, until we meet again..
