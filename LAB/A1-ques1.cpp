/// Program to find the maximum and minimum elements in a given array.
#include <iostream>
using namespace std;
int findMax(int* a, int size) {
    int m = a[0];
    for(int i = 1; i < size; ++i) {
        if(m < a[i]) {
            m = a[i];
        }
    }
    return m;
}
int findMin(int *a, int size)
{
    int m = a[0];
    for (int i = 1; i < size; ++i) {
        if (m > a[i]) {
            m = a[i];
        }
    }
    return m;
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements one by one" << endl;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int maximum = findMax(arr, n);
    int minimum = findMin(arr, n);
    cout << "The maximum no. is " << maximum << endl;
    cout << "The minimum no. is " << minimum << endl;
    return 0;
}