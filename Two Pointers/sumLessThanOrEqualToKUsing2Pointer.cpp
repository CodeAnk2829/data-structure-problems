// ques: 

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int largestSubArray(int n, int k, vector<int>& arr) {
    int maxLength = 0;
    int right = 0, left = 0;
    ll currentSum = 0;

    // sum must be <= k
    while(right < n) {
        currentSum += arr[right];
        // move the left pointer if the sum > k
        if(currentSum > k) {
            currentSum -= arr[left];
            left++;
        }
        maxLength = max(maxLength, right - left + 1);
        right++;
    }
    return maxLength;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int ans = largestSubArray(n, k, arr);
    cout << ans << endl;
    return 0;
}