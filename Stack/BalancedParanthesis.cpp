#include <bits/stdc++.h>
using namespace std;
bool isBalanced(string str) {
    stack <char> s;
    unordered_map <char, int> symbols = {{'[', -1}, {'{', -2}, {'(', -3}, {']', 1}, {'}', 2}, {')', 3}};
    for(auto &bracket : str) {
        if(symbols[bracket] < 0) {
            s.push(bracket);
        } else {
            if(s.empty()) return false;
            char t = s.top();
            s.pop();
            if(symbols[t] + symbols[bracket] != 0) {
                return false;
            }
        }
    }
    return s.empty();
}
int main() {
    
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        if(isBalanced(s)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
}