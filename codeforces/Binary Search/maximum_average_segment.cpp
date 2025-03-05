// problem link: https://codeforces.com/edu/course/2/lesson/6/4/practice/contest/285069/problem/A

#include <bits/stdc++.h>
using namespace std;

long double maximumSubArraySum(vector<long double>& arr, int d, int n) {
    vector<long double> prefixSum(n);
    prefixSum[0] = arr[0];
    for(int i = 1; i < n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    long double minimumSoFar = 0;
    long double ans = -1e18;
    for(int i = d - 1; i < n; ++i) {
        long double bestSubArraySumEndingHere = prefixSum[i] - minimumSoFar;
        minimumSoFar = min(minimumSoFar, prefixSum[i - d + 1]);
        ans = max(ans, bestSubArraySumEndingHere);
    }
    return ans;
}

bool isPossible(long double x, vector<long double>& arr, int d, int n) {
    vector<long double> transformedArr(n);
    for(int i = 0; i < n; ++i) {
        transformedArr[i] = arr[i] - x;
    }

    return maximumSubArraySum(transformedArr, d, n) >= 0;
}

pair<int, int> anySubArrayWithPositiveSum(vector<long double>& arr, int d, int n) { 
 vector<long double> prefixSum(n);
    prefixSum[0] = arr[0];
    for(int i = 1; i < n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    long double minimumSoFar = 0;
    int bestLeftIndex = -1;
    long double ans = -1e18;
    for(int right = d - 1; right < n; ++right) {
        long double bestSubArraySumEndingHere = prefixSum[right] - minimumSoFar;
        ans = max(ans, bestSubArraySumEndingHere);
        if(ans >= 0) {
            return make_pair(bestLeftIndex + 1, right);
        }

        if(minimumSoFar > prefixSum[right - d + 1]) {
            minimumSoFar = prefixSum[right - d + 1];
            bestLeftIndex = right - d + 1;
        }
    }
    return {-10, -10}; // randomly return because this is never going to happen
}

pair<int, int> bestSubArraySum(long double x, vector<long double> &arr, int d, int n) {
    vector<long double> transformedArr(n);
    for(int i = 0; i < n; ++i) {
        transformedArr[i] = arr[i] - x;
    }

    return anySubArrayWithPositiveSum(transformedArr, d, n);
}
int main() {
    int n, d;
    cin >> n >> d;
    vector<long double> arr(n);
    for(auto &i : arr) cin >> i;

    long double low = 0, high = 100;
    int iterations = 100;
    for(int i = 0; i <= iterations; i++) {
        long double mid = (high + low) / 2;
        if(isPossible(mid, arr, d, n)) {
            low = mid;
        } else {
            high = mid;
        }
    }
   
    pair<int, int> result = bestSubArraySum(low, arr, d, n);
    cout << result.first + 1 << " " << result.second + 1 << endl;
    return 0;
}