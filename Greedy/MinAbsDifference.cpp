// Leetcode problem 1200 - Minimum Absolute Difference
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> v;
        int k = 0;
        int ans = INT_MAX;
        for(int i = 1; i < arr.size(); ++i) {
            int diff = arr[i] - arr[i - 1];
            if(diff <= ans) {
                if(diff < ans && ans != INT_MAX) {
                    v.clear();
                }
                ans = diff;
                vector<int> temp(2);
                temp[0] = (arr[i - 1]);
                temp[1] = (arr[i]);
                v.push_back(temp);
            }
        }
        return v;
    }

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v;
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        vector<vector<int>> ans = minimumAbsDifference(v);
        for(int i = 0; i < ans.size(); ++i) {
            cout << ans[i][0] << " " << ans[i][1] << endl;
        }
    }
    return 0;
}