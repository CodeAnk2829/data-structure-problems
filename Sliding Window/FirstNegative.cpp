#include <bits/stdc++.h>
using namespace std;
vector<int> firstNegatives(vector<int>& arr, int k) {
    int n = arr.size();

    // find the first negatives from the window of size k
    queue<int> negatives;
    for(int i = 0; i < k - 1; ++i) {
        if(arr[i] < 0) {
            negatives.push(arr[i]);
        }
    }

    // find first negatives from each window of size k
    vector<int> ans;
    for(int i = 0, j = k - 1; i <= n - k; i++, j++) {
        // insert negatives
        if(arr[j] < 0) {
            negatives.push(arr[j]);
        }

        if(!negatives.empty()) {
            ans.push_back(negatives.front());
        } else {
            ans.push_back(0);
        }

        if(arr[i] < 0) {
            negatives.pop();
        }
    }

    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    for(int i = 0; i < n; ++i) {
        long x;
        cin >> x;
        arr.push_back(x);
    }

    vector<int> result = firstNegatives(arr, k);
    for(auto &x : result) {
        cout << x << " ";
    }
    return 0;
}