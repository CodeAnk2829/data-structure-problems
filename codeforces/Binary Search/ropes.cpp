// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isPossible(vector<int>& arr, double mid, int k) {
    ll totalCuts = 0;
    for(auto &i : arr) {
        totalCuts += (i / mid);
        if(totalCuts >= k) return true;
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];

    double low = 0, high = 1e7;
    double error = 1e-7;
    double ans = high;
    while(high - low > error) {
        double mid = (high + low) / 2;
        if(isPossible(arr, mid, k)) {
            low = mid + error;
            ans = mid;
        } else {
            high = mid - error;
        }
    }

    cout << setprecision(7) << fixed << ans << endl;
    return 0;
}