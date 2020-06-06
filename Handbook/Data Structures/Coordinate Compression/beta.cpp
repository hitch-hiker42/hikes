//author: hitch_hiker42;
void compress(vector<int>& a, int& m, map<int, int>& hash) {
    set<int> filter;
    for(auto& i: a) filter.insert(i);
    m = 0;
    for(auto& i: filter) hash[i] = ++m;
    for(auto& i: a) i = hash[i];
    map<int, int> invert;
    for(auto& [x, y]: hash) invert[y] = x;
    hash = invert;
} //farewell, until we meet again..
