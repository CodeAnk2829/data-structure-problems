#include <bits/stdc++.h>
using namespace std;
void bubble_sort(int *a, int size) {
    for(int r = 1; r < size; ++r) {
        for(int i = 0; i < size - r; ++i) {
            if(a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    bubble_sort(arr, n);
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    return 0;
}