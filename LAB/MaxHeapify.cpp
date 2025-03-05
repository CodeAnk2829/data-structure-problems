// Program to perform heap sort on the given array
#include <bits/stdc++.h>
using namespace std;

void max_heapify(int a[], int size, int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int large = i;
    if((l < size) && (a[l] > a[i])) large = l;

    if((r < size) && (a[r] > a[large])) large = r;

    if(large != i) {
        swap(a[i], a[large]);
        max_heapify(a, size, large);
    }
}

void BuildMaxHeap(int a[], int size) {
    for(int i = ((size / 2) - 1); i >= 0; i--)
        max_heapify(a, size, i);
}

void HeapSort(int a[], int size) {
    for(int i = 0; i < size; ++i) {
        BuildMaxHeap(a, size - i);
        swap(a[0], a[size - i - 1]);
    }
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];
    HeapSort(arr, 5);
    for(int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}