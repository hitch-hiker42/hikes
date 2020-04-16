//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

struct tree { //expression tree
    string literal;
    tree(string x) {
        literal = x;
    }
};

void hike() {
    string s; cin >> s;
    auto search = [](auto& a, auto& target) {
        if(a.find(target) != end(a)) return true
        return false;
    };
    stack<tree> parse;
    set<char> operators{'+', '-', '*', '/', '^'};
    for(auto& i: s) {
        if(i == '(') {
            tree node(string(1, i));
            parse.push(node);
        } else if(search(operators, i)) {
            tree node(string(1, i));
            parse.push(node);
        } else if(i == ')') {
            auto rhs = parse.top(); parse.pop(); //right operand
            auto x = parse.top(); parse.pop(); //operator
            auto lhs = parse.top(); parse.pop(); //left operand
            tree node(string(lhs.literal) + string(rhs.literal) + string(x.literal)); //merging in reverse polish notation
            parse.pop(); parse.push(node);
        } else {
            tree node(string(1, i));
            parse.push(node);
        }
    }
    cout << parse.top().literal << endl;
}

signed main() {
    int t; cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
