#include <bits/stdc++.h>
using namespace std;
void insertion_sort(int *a, int size) {
    for(int i = 1; i < size; ++i) {
        int key = a[i];
        int j = i - 1;
        while(a[j] > key && j >= 0) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    insertion_sort(arr, n);
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    return 0;
}