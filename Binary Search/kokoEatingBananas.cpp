// https://leetcode.com/problems/koko-eating-bananas/
#include <bits/stdc++.h>
using namespace std;

long long findrequiredTime(vector<int>& piles, long long n) {
    long long requiredTime = 0;
    for(int i = 0; i < piles.size(); ++i) {
        // take ceil values
        requiredTime += (piles[i] % n == 0) ? (piles[i] / n) : (piles[i] / n + 1);
    }
    return requiredTime;
}

int minEatingSpeed(vector<int>& piles, int h) {
    long long low = 1, high = *max_element(piles.begin(), piles.end());
    int ans = high;
    while(low <= high) {
        long long mid = low + (high - low) / 2;
        long long requiredTime = findrequiredTime(piles, mid);
        if(requiredTime <= h) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> piles(n);
    for(int i = 0; i < n; ++i) cin >> piles[i];
    int hours;
    cin >> hours;

    int minSpeed = minEatingSpeed(piles, hours);
    return 0;
}