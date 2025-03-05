// 1482. Minimum Number of Days to Make m Bouquets
// https: // leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

#include <bits/stdc++.h>
using namespace std;

int getBouquets(vector<int>& bloomDays, int k, int n) {
    int count = 0, numBouquets = 0;
    for(int i = 0; i < bloomDays.size(); ++i) {
        if(bloomDays[i] <= n) {
            count++;
        } else {
            numBouquets += (count / k);
            count = 0;
        }
    }
    numBouquets += (count / k);
    return numBouquets;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    if(m > bloomDay.size() / k) return -1;

    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());

    while(low <= high) {
        int mid = low + (high - low) / 2;
        int numBouquets = getBouquets(bloomDay, k, mid);
        if(numBouquets >= m) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}