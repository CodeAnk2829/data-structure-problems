// https://cses.fi/problemset/task/1085
#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool predicateFunction(vector<ll>& arr, ll workload, ll k) {
    // returns true if array can be split into k segments such that 
    // every segment has sum <= x
    ll sum = 0, segments = 1;
    ll size = arr.size();
    for(ll i = 0; i < size; ++i) {
        sum += arr[i];
        if(sum > workload) {
            sum = arr[i];
            segments++;
        }
    }
    return segments <= k;
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(ll i = 0; i < n; ++i) cin >> arr[i];

    ll low = *max_element(arr.begin(), arr.end());
    ll high = accumulate(arr.begin(), arr.end(), 0LL);
    
    ll candidateSolution = low;
    while(low <= high) {
        ll mid = low + (high - low) / 2;
        
        if(predicateFunction(arr, mid, k)) {
            high = mid - 1;
            candidateSolution = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << candidateSolution;
    return 0;
}