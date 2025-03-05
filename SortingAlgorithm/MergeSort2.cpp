// Second program for merge sort which can be used to solve different problems like Inversion count
#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& arr, int l, int m, int r) {
    int i = l, j = m, k = 0;
    int temp[r - l + 1];
    while(i < m && j <= r) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while(i < m) {
        temp[k++] = arr[i++];
    }
    while(j <= r) {
        temp[k++] = arr[j++];
    }
    for(int i = l, k = 0; i <= r; ++i, ++k) {
        arr[i] = temp[k];
    }
}
void mergeSort(vector<int>& arr, int l, int r) {
    if(l >= r) return;
    int mid = (l + r)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid + 1, r);
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    mergeSort(a, 0, n - 1);
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    return 0;
}