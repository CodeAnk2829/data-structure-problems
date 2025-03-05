// https://leetcode.com/problems/find-the-duplicate-number/
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    bool isPossible(vector<int>& nums, int mid) {
        int count = 0;
        for(auto &i : nums) {
            if(i <= mid) {
                count++;
            }
            if(count > mid) return true;
        }
        return false;
    }
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1;
        int ans = 1;
        while(low <= high) {
            int mid = (high + low) / 2;
            if(isPossible(nums, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};