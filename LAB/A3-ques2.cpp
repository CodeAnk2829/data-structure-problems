// Program to merge two sorted arrays into an array.
#include <iostream>
using namespace std;
int main() {
    // Input in the first array
    int n;
    cout << "Element no. of elements for the first array: ";
    cin >> n;
    int sortedArray1[n];
    cout << "Enter " << n << " elements in sorted order" << endl;
    for(int i = 0; i < n; ++i) {
        cin >> sortedArray1[i];
    }

    // Input in the second array
    int m;
    cout << "Element no. of elements for the second array: ";
    cin >> m;
    int sortedArray2[m];
    cout << "Enter " << m << " elements in sorted order" << endl;
    for (int i = 0; i < m; ++i) {
        cin >> sortedArray2[i];
    }
    
    int mergedArray[n + m];

    // Merging two sorted arrays
    for(int i = 0; i < (n + m); ++i) {
        if(i < n) {
            mergedArray[i] = sortedArray1[i];
        } else {
            mergedArray[i] = sortedArray2[i - n];
        }
    }

    // Print
    cout << "The new array after merging two given sorted arrays: " << endl;
    for(int i = 0; i < (n + m); ++i) {
        cout << mergedArray[i] << " ";
    }
    return 0;
}