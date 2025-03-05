// Program to reverse an array.
#include <iostream>
using namespace std;
void reverseArray(int *a, int size) {
    for(int i = 0; i < size/2; ++i) {
        swap(a[i], a[size - 1 - i]);
    }
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements one by one" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << "Before Reversing" << endl;
    for(int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\nAfter Reversing"  << endl;
    reverseArray(arr, n);
    for(int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}