#include <bits/stdc++.h>
#include "Trie.h" 
int main() {
    string s;
    cin >> s;
    Trie t;
    map<string, int> m;
    for(int i = 0; i < s.size(); ++i) {
        for(int j = i; j < s.size(); ++j) {
            string temp = s.substr(i, j - i + 1);
            t.insertWord(temp);
            m[temp]++;
        }
    }
   
    int n;
    cin >> n;
    int count = 0;
    for(int i = 0; i < n; ++i) {
        string temp;
        cin >> temp;
        if(t.searchWord(temp)) {
            count += m[temp];
        }
    }
    for(auto &it : m) {
        cout << it.first << " -> " << it.second << endl;
    }
    cout << s.size() - count << endl;

        // t.insertWord("are");
        // t.insertWord("and");
        // t.insertWord("dot");
        // cout <<  t.searchWord("an") << endl;
        // cout <<  t.searchWord("and") << endl;
        // t.removeWord("and");
        // cout << t.searchWord("and") << endl;
        return 0;
}
