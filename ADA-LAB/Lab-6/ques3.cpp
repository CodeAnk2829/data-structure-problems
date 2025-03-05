// Quick sort using random pivot
#include <bits/stdc++.h>
using namespace std;
int partition(int arr[], int low, int high) {
    int random = low + (rand() % (high - low + 1));
    swap(arr[random], arr[high]);
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
    cout << "Enter size:" << endl;
    cin >> n;

    int a[n];
    cout << "Enter elements: " << endl;
    for(int i = 0; i < n; ++i) cin >> a[i];

    quickSort(a, 0, n - 1);
    
    cout << "After sorting: " << endl;
    for(int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    return 0;
}