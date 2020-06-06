//author: hitch_hiker42;
#define span(a) begin(a), end(a)

void compress(vector<int>& sparse, int& m, map<int, int>& hash) {
    int n = sparse.size();
    vector<int> order(span(sparse)), dense;
    sort(span(order));
    for(int i = 0; i < n; ++i) {
        dense[i] = distance(begin(order), lower_bound(span(order), sparse[i])) + 1;
        hash[dense[i]] = sparse[i];
    }
    m = *max_element(span(dense));
} //farewell, until we meet again..
