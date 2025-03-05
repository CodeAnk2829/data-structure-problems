// Extract K largest elements from the given array by using quickSelect method
// quickSelect method is based on the idea of quickSort method
// Time Complexity: O(N + KlogK)--> Avg case && O(n ^ n) in worst case
// Space Complexity O(k);

#include <bits/stdc++.h> 
using namespace std;

int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[low];
    int pivotIndex = high + 1;
    for(int i = high; i > low; --i) {
        if(arr[i] >= pivot) {
            swap(arr[--pivotIndex], arr[i]);
        }
    }
    // swap to find the correct position of pivot
    swap(arr[--pivotIndex], arr[low]);
    return pivotIndex;
}

int quickSelect(vector<int> &a, int low, int high, int k) {
    if(k > 0 && k <= high - low + 1) {
        // find actual position of the kth largest element
        int pivotIndex = partition(a, low, high);
        
        // count the no. of elements in the resulting array
        int countKLargest = high - pivotIndex + 1;

        // if no. of elements is same as k then actual
        // actual position of kth largest element has found 
        // hence return it
        if(countKLargest == k) {
            return a[pivotIndex];
        }

        // if no. of elements is greater than k then recur to right subarray
        if(countKLargest > k) {
            return quickSelect(a, pivotIndex + 1, high, k);
        }

        // otherwise recur to the left subarray
        return quickSelect(a, low, pivotIndex - 1, k - countKLargest);
    }
    // if no. of k is greater than number of elements in the array
    return INT_MIN;
}

vector<int> Klargest(vector<int> &a, int k, int n) {
    // arrange k largest elements at right subarray 
    quickSelect(a, 0, n - 1, k);

    vector<int> res(k);

    // store k largest elements
    for(int i = n - k, j = 0; j < k; ++i, ++j) {
        res[j] = a[i];
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<int> res = Klargest(v, k, n);
    return 0;
}