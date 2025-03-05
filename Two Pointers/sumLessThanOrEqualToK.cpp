#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll subarraySum(int l, int r, vector<ll>& prefix) {
    ll right = prefix[r];
    ll left = l > 0 ? prefix[l - 1] : 0LL;
    return right - left;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // calculate prefix sum 
    vector<ll> prefix(n);
    prefix[0] = arr[0];
    for(int i = 1; i < n; ++i) {
        prefix[i] = prefix[i - 1] + ll(arr[i]);
    }
    
    int ans = 0;
    int finalAns = 0;

    for(int i = 0; i < n; ++i) {
        // for each index in the array find out the maximum 
        // length of subarray whose sum <= k
        int start = 0, end = n - 1;
        while(start <= end) {
            int mid = (start + end) / 2;
            if(subarraySum(i, mid, prefix) <= k) {
                ans = mid - i + 1;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        finalAns = max(finalAns, ans);
    }
    cout << finalAns << endl;
    return 0;
}