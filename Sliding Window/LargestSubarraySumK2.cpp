// Find the length of largest subarray having sum equal to k
// Elements of the array are Integers (positive + negative)
// Hashing technique
// TC = O(n * log n) --> for ordered map
// Tc = O(n) --> best case and O(n^2) -->worst case --> for unordered map

#include <bits/stdc++.h>
using namespace std;
int longestSubarrayWithSumK(vector<int>& arr, long long k) {
    map<long long, int> preSumMap; // store prefixsum as key and index as value
    int prefixSum = 0;
    preSumMap[prefixSum] = -1;
    int len = 0;

    for(int i = 0; i < arr.size(); ++i) {
        prefixSum += arr[i];
        // find the remaining sum 
        int rem = prefixSum - k;

        // if remaining sum has previously been calculated 
        // then it would be found in hashmap and length can 
        // be updated accordingly
        if(preSumMap.find(rem) != preSumMap.end()) {
            len = max(len, i - preSumMap[rem]);
        }

        // if prefixSum does not exist yet then add it to the
        // hashmap otherwise don't update it because we need 
        // the subarray as large as possible..This will occur when
        // 0s come in our element
        if(preSumMap.find(prefixSum) == preSumMap.end()) {
            preSumMap[prefixSum] = i;
        }
    }

    return len;
}