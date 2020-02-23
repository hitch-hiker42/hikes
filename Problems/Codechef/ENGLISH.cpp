//author: hitch_hiker42;
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;

//macro definitions and symbolic constants:
#define syncboost ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define loop(i, begin, end) for(__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define span(v) (v).begin(), (v).end()
#define x first
#define y second
#define precise(n) cout << fixed; cout << setprecision(n)
#define endl '\n'
#define debug
//#define pipeline
enum constants {zero, unit, two, three, four, five, six, seven, eight, nine, infmin = numeric_limits<int>::min(), infmax = numeric_limits<int>::max(), mod = int(1e9 + 7)};

//debugging:
#ifdef debug
//#define cerr cout //redirect error messages to stdout instead of stderr;
#define trace(...) error(#__VA_ARGS__, __VA_ARGS__)
template <class Qux>
void error(const char* foo, Qux&& bar) {
    cerr << foo << " : " <<  bar << endl;
}
template <class John, class... Doe>
void error(const char* foo, John&& bar, Doe&&... args) {
    const char* comma = strchr(foo + 1, ',');
    cerr.write(foo, comma - foo) << " : " << bar <<" | ";
    error(comma+1, args...);
}
#else
#define trace(...) //define customized trace tool;
#endif

//solution:
const int alphasize = 26;
const int offset = 'a';

struct trie {
    //attributes:
    trie* key[alphasize][alphasize]; //holds the sub-tries (defined recursively), each node will have at most (alphabet size)^2 children;
    map<trie*, trie*> p; //to hold the parent for each key (or node) - the parent of the root is set to nullptr;
    bool end; //to mark the end of a word (normalization makes sure there aren't any duplicates);
    //member functions:
    trie(trie* parent) {
        for(auto& i: key) {
            for(auto& j: i) {
                j = nullptr;
            }
        }
        end = false;
        p[this] = parent;
    }
    bool isleaf(trie* node) { //checks if the passed node is a leaf;
        for(int i = 0; i < alphasize; ++i) {
            for(int j = 0; j < alphasize; ++j) {
                if(node -> key[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool search(string& word) { //to test the presence of a word in the trie;
        int n = word.length(), i, j;
        trie* nav = this; //to navigate through trie;
        for(i = 0, j = n - 1; i < n; ++i, --j) {
            if(!(nav -> key[word[i] - offset][word[j] - offset])) {
                return false;
            }
            nav = nav -> key[word[i] - offset][word[j] - offset];
        }
        if(nav -> end) {
            return true;
        }
    }
    void insert(string& word) {
        int n = word.length(), i, j;
        trie* nav = this; //to navigate through trie;
        for(i = 0, j = n - 1; i < n; ++i, --j) {
            if(!(nav -> key[word[i] - offset][word[j] - offset])) {
                nav -> key[word[i] - offset][word[j] - offset] = new trie(nav);
            }
            nav = nav -> key[word[i] - offset][word[j] - offset];
        }
        nav -> end = true;
    }
};

pair<int64_t, int64_t> beautify(trie* root, int level) {
    int64_t beauty(0), request(0); char u, v;
    for(int i = 0; i < alphasize; ++i) {
        for(int j = 0; j < alphasize; ++j) {
            if(root -> key[i][j]) {
                pair<int64_t, int64_t> collect = beautify(root -> key[i][j], level + unit);
                beauty += collect.x;
                request += collect.y;
            }
            else {
                continue;
            }
        }
    }
    if(root -> end) {
        if(root -> isleaf(root)) {
            return {beauty, request + unit};
        }
        else {
            request = request + unit;
            beauty += ((request >> unit)) * (level * level);
            request -= ((request >> unit) << unit);
            return {beauty, request};
        }
    }
    else { //handling requests at lca;
        beauty += (request >> unit) * (level * level);
        request -= ((request >> unit) << unit);
        return {beauty, request};
    }
}

void solution() {
    int64_t n, beauty(0); cin >> n;
    vector<string> words(n);
    map<string, int64_t> freq;
    for(string& i: words) {
        cin >> i;
        freq[i]++;
    }
    words.clear();
    
    //matching equal strings, hence removing duplicates(call it, the normalization step):
    for(auto& i: freq) {
        if(i.y >= two) {
            beauty += (i.y >> unit) * (i.x.size() * i.x.size());
            i.y -= ((i.y >> unit) << unit);
        } //to be continued..
        if(i.y) {
           words.push_back(i.x); 
        }
    }
    
    /* Constructing the trie with the given list of words (after normalization):
     * each node holds a two dimensional matrix of children, 
     * in which a children node[i][j] corresponds to the i-th 
     * character in the alphabet (from the left) and the j-th 
     * character in the alphabet (from the right);
     * going down the levels signifies passing through strings 
     * from either side - left and right (with the k-th level 
     * corresponding to k-characters traversed from either side);
     */
     
    trie* root = new trie(nullptr); //setting the root of the trie;
    for(string& i: words) {
        root -> insert(i);
    }
    
    //continue.. building up the most beautiful verse:
    beauty += beautify(root, zero).x;
    cout << beauty << endl;
}

signed main() {
    //auto start = chrono::system_clock::now();
    #ifdef pipeline
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    syncboost; precise(10);
    int t = unit; cin >> t;
    while(t--) {
        solution();
    }
    //cerr << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;
    return 0;
} //farewell.. until we meet again;
