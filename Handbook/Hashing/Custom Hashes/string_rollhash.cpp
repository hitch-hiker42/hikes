//author: hitch_hiker42;
#define int int64_t

int rollhash(string const& s) {
    int hash = 0, x = 1;
    for(const char& c: s) {
        (hash += (c - 'a' + 1) * x % mod) %= mod;
        x = x * p % mod;
    }
    return hash;
}

bool equal(const string& s, const string& t) {
    return !(s.compare(t));
}

struct custom {
    size_t operator () (const string& s) const {
        return rollhash(s);
    }
};

unordered_map<string, int, custom, equal> f;
//farewell, until we meet again..
