#include <bits/stdc++.h>
using namespace std;
typedef pair<int, char> p;
string frequencySort(string s) {
    map<char, int> freqChar;
    for(auto &ch : s) {
        freqChar[ch]++;
    }
    // for(auto &ch : freqChar) {
    //     cout << ch.first << " " << ch.second << endl;
    // }
    priority_queue<p> pq;
    for(auto &m : freqChar) {
        pq.push({m.second, m.first});
    }
    while(!pq.empty()) {
        cout << pq.top().second << " " << pq.top().first << endl;
        pq.pop();
    }
    string res;
    // while(!pq.empty()) {
    //     for(int i = 0; i < pq.top().first; ++i) {
    //         res.push_back(pq.top().second);
    //     }
    //     pq.pop();
    // }
    return res;
}

int main() {
    string s;
    cin >> s;
    cout << frequencySort(s);
    return 0;
}