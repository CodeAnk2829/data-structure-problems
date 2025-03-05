#include <bits/stdc++.h>
using namespace std;
int partition(int arr[], int low, int high) {
    // Use current time as seed for random generator
    srand(time(0));
    // generate random pivot index
    int pivotIndex = (rand() % (high - low + 1)) + low;
    cout << "PivotIndex : " << pivotIndex << endl;

    // select a random pivot from the given array
    int pivot = arr[pivotIndex];
    int lb = low;
    int ub = high;

    while(lb < ub) {
        while(arr[lb] <= pivot) {
            lb++;
        }
        while(arr[ub] > pivot) {
            ub--;
        }
        if(lb < ub) {
            cout << lb << " " << ub << endl;
            swap(arr[lb], arr[ub]);
        }
    }
    swap(arr[ub], arr[pivotIndex]);
    pivotIndex = ub;
    return pivotIndex;
}


int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];
    partition(arr, 0, n - 1);
    for(int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}