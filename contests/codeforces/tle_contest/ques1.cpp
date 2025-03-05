#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    map<char, int> m;
    for(int i = 0; i < n; ++i) {
        string temp;
        cin >> temp;
        m[temp[0]]++;
    }

    int minimumChattyPairs = 0;
    for(auto &i : m) {
        int x = i.second >> 1;
        if(i.second & 1) {
            minimumChattyPairs += (x * x);
        } else {
            minimumChattyPairs += (x * (x - 1));
        }
    }

    cout << minimumChattyPairs;
    return 0;
}