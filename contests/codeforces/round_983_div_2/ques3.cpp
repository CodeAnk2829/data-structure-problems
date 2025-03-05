#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;

int findValidIndex(int target, vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    while(low <= high) {
        int mid = (high + low) / 2;
        if(arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto &i : arr) cin >> i;

        // since order doesn't matter so we can sort the array for our purpose
        sort(arr.begin(), arr.end());

        // INTUITION: 1. sum(smallest + second smallest) > largest
        //            2. find the length of largest valid subArray, x (say)
        //            3. the minimum number of operations would be (n - x)
        
        int largestValidLength = 0;

        for(int i = 0; i < n - 1; ++i) {
            int sumOfCurrSmallestAndSecondSmallestElements = arr[i] + arr[i + 1];
            int indexOfDegeneratedTriangle = findValidIndex(sumOfCurrSmallestAndSecondSmallestElements, arr);
            largestValidLength = max(largestValidLength, indexOfDegeneratedTriangle - i);
        }

        int minimumOperations = n - largestValidLength;
        cout << minimumOperations << endl;
    }
    return 0;
}
