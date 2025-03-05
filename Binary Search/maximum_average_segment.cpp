#include <bits/stdc++.h>
using namespace std;

bool isPossible(int mid, vector<int>& arr) {
    int sum = accumulate(arr.begin(), arr.begin() + mid, 0);
    for(int i = mid; i < arr.size(); ++i) {
        sum += (arr[i] - arr[i - mid]);
        
    }
}

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    for(auto &i : arr) cin >> i;

    int low = d, high = n;
    int ans = low;

    while(low <= high) {
        int mid = (high + low) / 2;
        if(isPossible(mid, arr)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans;
    return 0;
}