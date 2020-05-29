//skiplists:
cout << "{";
for(int i = 1; i < cycle[3].size(); i++) {
    cout << cycle[3][i] - cycle[3][i - 1] << ", ";
}
cout << "}";

//hashes:
cout << "{";
for(int i = 0; i < cycle[3].size() - 1; i++) {
    cout << "{" << cycle[3][i]<< ", " << i << "}, ";
}
cout << "}";
