// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:  
    // predicate function
    bool isPossible(vector<int>& bloomDay, int day, int m, int k) {
        int n = bloomDay.size();
        int numOfBouquets = 0;
        int i = 0;
        while(i < n) {
            int j = i;
            while(j < n && j < (k + i) && bloomDay[j] <= day) {
                j++;
            }
            if(j == k + i) {
                numOfBouquets++;
            } else {
                j++;
            }
            i = j;
        }
        return numOfBouquets >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m > (n / k)) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = high;
        while(low <= high) {
            int mid = (high + low) / 2;
            if(isPossible(bloomDay, mid, m, k)) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};