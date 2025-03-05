// Program to search for a given element in an array.
#include <iostream>
using namespace std;
int searchElement(int* a, int size, int k) {
    int i = 0;
    while(i < size && k != a[i]) {
        i++;
    }
    if(i == size) {
        return -1;
    } 
    return i;
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
    cout << "Enter key to be searched: ";
    int key;
    cin >> key;
    int indexAtElement= searchElement(arr, n, key);
    if(indexAtElement != -1) {
        cout << "The index at which the given element is present is " << indexAtElement << endl;
    } else {
        cout << "Element not found!" << endl;
    }
    return 0;
}