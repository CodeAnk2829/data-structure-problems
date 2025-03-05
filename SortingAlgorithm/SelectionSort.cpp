#include <bits/stdc++.h>
using namespace std;
// void selection_sort(int *a, int size) {
//     for(int r = 0; r < size - 1; ++r) {
//         swap(a[r], *min_element(a + r, a + size));
//     }
// }
void selection_sort(int *a, int size) {
    for(int pos = 0; pos < size - 1; ++pos) {
        int min = a[pos], j = pos;

        // Finding the minimum element each time
        for(int i = pos + 1; i < size; ++i) {
            if(min > a[i]) {
                min = a[i];
                j = i;
            }
        }
        if(a[j] != a[pos])
            swap(a[pos], a[j]);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    selection_sort(arr, n);
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    return 0;
}