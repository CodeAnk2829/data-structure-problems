// https://codeforces.com/problemset/problem/1843/E
#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<pair<int, int>>& ranges, vector<int>& indices, int n, int changeUpto) {
    vector<int> zeros(n, 0);

    for(int i = 0; i < changeUpto; ++i) {
        int desiredIndex = indices[i] - 1;
        zeros[desiredIndex] = 1;
    }

    vector<int> prefixSum(n + 1, 0);
    for(int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + zeros[i];
    }

    for(auto &range : ranges) {
        int totalElementsInThisRange = range.second - range.first + 1;
        int numOfOnesInThisRange = prefixSum[range.second] - prefixSum[range.first - 1];
        int numOfZerosInThisRange = totalElementsInThisRange - numOfOnesInThisRange;
        if(numOfZerosInThisRange < numOfOnesInThisRange) return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> ranges(m);
        for(auto &i : ranges) cin >> i.first >> i.second;
        int q;
        cin >> q;
        vector<int> indices(q);
        for(auto &i : indices) cin >> i;

        int low = 1, high = q;
        int ans = -1;
        while(low <= high) {
            int mid = (high + low) / 2;
            if(isPossible(ranges, indices, n, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}