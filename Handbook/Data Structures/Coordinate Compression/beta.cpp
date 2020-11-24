//author: hitch_hiker42;
auto compress(vector<int>& sparse, vector<int>& invert) {
  int idx = 1, n = sparse.size();
  map<int, int> hash;
  vector<int> order(span(sparse));
  sort(span(order));
  for(auto& i: order) {
    if(!hash[i]) hash[i] = idx, invert[idx] = i, idx++;
  }
  vector<int> dense(n);
  for(int i = 0; i < n; ++i) dense[i] = hash[sparse[i]];
  return move(dense);
} //farewell, until we meet again..
