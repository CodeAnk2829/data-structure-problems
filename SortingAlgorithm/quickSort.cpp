// Program to perform quick sort in a given array
#include <bits/stdc++.h>
using namespace std;
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    // Partitioning
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            swap(arr[++i], arr[j]);
        }
    }
    swap(arr[++i], arr[high]);
    return i; // pivotIndex
}
void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];
    quickSort(a, 0, n - 1);
    for(int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    return 0;
}