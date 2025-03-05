#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
    int n = nums.size();
    int minVal = INT_MAX;
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        // left half is sorted
        if(nums[low] <= nums[mid]) {
            minVal = min(minVal, nums[low]);
            // trim down the left search space
            low = mid + 1;
        } else { // right half is sorted
            minVal = min(minVal, nums[mid]);
            // trim down the right search space
            high = mid - 1;
        }
    }
    return minVal;
}