//author: hitch_hiker42;
constexpr int b = 5;
int basis[b] = {2, 3, 5, 7, 11}, w[b];
vector<int> stokes[b], skip[b];
map<int, int> wheel[b];

void construct() {
    for(int j = 1; j <= b; ++j) {
        vector<int> base(begin(basis), begin(basis) + j);
        //circumference:
        w[j - 1] = accumulate(span(base), 1, multiplies<int>());

        //stokes:
        vector<bool> p(w[j - 1], true);
        p[0] = false;
        for(int& i: base) {
            p[i] = false;
            for(int k = i * i; k < w[j - 1]; k += i) p[k] = false;
        }
        for(int i = 1; i < w[j - 1]; ++i) if(p[i]) stokes[j - 1].emplace_back(i);

        //skiplists:
        for(int i = 1, z = (int)stokes[j - 1].size(); i < z; ++i) {
            skip[j - 1].emplace_back(stokes[j - 1][i] - stokes[j - 1][i - 1]);
        }
        skip[j - 1].emplace_back(2);

        //wheel hashes:
        for(int i = 0, z = (int)skip[j - 1].size(); i < z; ++i) {
            wheel[j - 1][stokes[j - 1][i]] = i;
        }
    }
} //farewell, until we meet again..
