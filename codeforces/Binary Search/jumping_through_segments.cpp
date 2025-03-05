// https://codeforces.com/problemset/problem/1907/D
#include <bits/stdc++.h>
using namespace std;

int isPossible(vector<vector<int>>& segments, int maxDistance) {
    vector<int> range = {-maxDistance, maxDistance};
    
    for(auto s : segments) {
        // calculate intersection
        int intersectionX = max(range[0], s[0]);
        int intersectionY = min(range[1], s[1]);

        if(intersectionX > intersectionY) {
            return false;
        }
        range[0] = intersectionX - maxDistance;
        range[1] = intersectionY + maxDistance;
    }
    return true;
}

int main() {
    int t; 
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(2, 0));
        for(int i = 0; i < n; ++i) {
            cin >> arr[i][0] >> arr[i][1];
        }

        int low = 0, high = 1e9;
        int ans = high;
        
        while(low <= high) {
            int mid = (high + low) / 2;
            if(isPossible(arr, mid)) {
                high = mid - 1;
                ans = mid; 
            } else {
                low = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}