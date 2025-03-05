
#include <bits/stdc++.h>
using namespace std;
int comparisonBS = 0;
int comparisonTS = 0;
// Function to perform Binary Search
void binary_search(int v[], int lo, int hi, int key) {
    if(lo > hi) {
        cout << "Key Not found" << endl;
        return;
    }

    int mid = (lo + hi)/2;
    comparisonBS++;
    if(v[mid] == key) {
        cout << "Using Binary Search --> Key found at " << mid << endl;
        return;
    }
    comparisonBS++;
    if(v[mid] < key) {
        binary_search(v, mid + 1, hi, key);
    } else {
        binary_search(v, lo, mid, key);
    }
}
  
// Function to perform Ternary Search
int ternarySearch(int ar[], int l, int r, int key)
{
    if (r >= l) {
  
        // Find the mid1 and mid2
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
  
        // Check if key is present at any mid
        comparisonTS++;
        if (ar[mid1] == key) {
            return mid1;
        }
        comparisonTS++;
        if (ar[mid2] == key) {
            return mid2;
        }
        comparisonTS++;
        if (key < ar[mid1]) {
            return ternarySearch(ar, l, mid1 - 1, key);
        } else if (key > ar[mid2]) {
            return ternarySearch(ar, mid2 + 1, r, key);
        } else {
            return ternarySearch(ar, mid1 + 1, mid2 - 1, key);
        }
    }
  
    // Key not found
    return -1;
}
  
int main()
{
    int n;
    cout << "Enter size: " << endl;
    cin >> n;
  
    int a[n];
    cout << "Enter elements: " << endl;
    for(int i = 0; i < n; ++i) cin >> a[i];
    
    int key;
    cout << "Enter key to be searched: " << endl;
    cin >> key;

    // Sort the array
    sort(a, a + n);

    // Search the key using ternarySearch
    int index_of_key = ternarySearch(a, 0, n - 1, key);

    if(index_of_key == -1) {
        cout << "Key not found" << endl;
    } else {
        cout << "Using Ternary Search --> Key found at " << index_of_key << endl;
    }

    // Search the key using Binary
    binary_search(a, 0, n - 1, key);

    cout << "No. of comparisons in Binary Search: " << comparisonBS << endl;
    cout << "No. of comparisons in Ternary Search: " << comparisonTS << endl;

    return 0;
}