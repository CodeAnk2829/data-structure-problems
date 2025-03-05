#include <bits/stdc++.h>
using namespace std;

vector<int> findKLargest(map<int, int>& m, int k) {
    priority_queue<int, vector<int>, greater<int>> kLargestElements;
    for(auto &i : m) {
        kLargestElements.push(i.second);
        if(kLargestElements.size() > k) {
            kLargestElements.pop();
        }
    }

    vector<int> result;
    while(!kLargestElements.empty()) {
        result.push_back(kLargestElements.top());
        kLargestElements.pop();
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        map<int, int> m;
        for(int i = 0; i < k; ++i) {
            int brand, cost;
            cin >> brand >> cost;
            m[brand] += cost;
        }

        int maxCost = 0;
        if(m.size() > n) {
            int cnt = 0;
            vector<int> result = findKLargest(m, n);
            for(auto i : result) {
                maxCost += i;
            }
        } else {
            for(auto &i : m) {
                maxCost += i.second;
            }
        }
        cout << maxCost << endl;
    }
    return 0;
}