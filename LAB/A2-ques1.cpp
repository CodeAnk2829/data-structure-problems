// Program to calculate sum of the elements in the given array.
#include <iostream>
using namespace std;
int calculateSum(int* a, int size) {
    int sum = 0;
    for(int i = 0; i < size; ++i) {
        if(i & 1) {
            sum += a[i];
        }
    }
    return sum;
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
    int result = calculateSum(arr, n);
    cout << "The sum of the elements at odd positions is: " << result;
    return 0;
}