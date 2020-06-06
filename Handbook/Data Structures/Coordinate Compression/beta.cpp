//author: hitch_hiker42;
void compress(vector<int>& a, int& m, map<int, int>& hash) {
    set<int> filter;
    for(auto& i: a) filter.insert(i);
    int j = 1;
    for(auto& i: filter) hash[i] = j++;
    m = j - 1;
    for(auto& i: a) i = hash[i];
    map<int, int> invert;
    for(auto& [x, y]: hash) invert[y] = x;
    hash = invert;
} //farewell, until we meet again..
