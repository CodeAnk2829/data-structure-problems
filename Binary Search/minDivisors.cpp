// 1283. Find the Smallest Divisor Given a Threshold
// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
#include <bits/stdc++.h>
using namespace std;

int findSum(vector<int>& nums, int d, int t) {
    int sum = 0;
    for(int i = 0; i < nums.size(); ++i) {
        sum += (nums[i] % d == 0) ? (nums[i] / d) : (nums[i] / d + 1);
    }
    return sum;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1, high = *max_element(nums.begin(), nums.end());
    int mini = high;

    while(low <= high) {
        // divisor 
        int mid = low + (high - low) / 2;
        int sumQuotients = findSum(nums, mid, threshold);
        if(sumQuotients <= threshold) {
            mini = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return mini;
}