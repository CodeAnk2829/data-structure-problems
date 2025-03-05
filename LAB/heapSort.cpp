// Program to preform heap sort on a given array
#include <bits/stdc++.h>
using namespace std;
void maxHeapify(int arr[], int size, int i) {
    // Initialize largest as root
    int largest = i;

    int l = 2 * i + 1;
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < size && arr[l] > arr[largest]) largest = l;

    // If right child is larger than largest
    if (r < size && arr[r] > arr[largest]) largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively maxHeapify the affected sub tree
        maxHeapify(arr, size, largest);
    }
}
void heapSort(int arr[], int size) {

    // Build heap (rearrange array)
    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, size, i);
    }

    for (int i = size - 1; i > 0; i--) {

        // Move current root to end
        swap(arr[0], arr[i]);

        // call maxHeapify on the reduced heap
        maxHeapify(arr, i, 0);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    heapSort(a, n);
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    return 0;
}