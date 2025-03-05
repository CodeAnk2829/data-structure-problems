#include <bits/stdc++.h>
using namespace std;

// find array of differences of every possible pairs of elements
// in the given array
vector<pair<int, pair<int, int>>> findDiffArray(int A[], int size) {
    vector<pair<int, pair<int, int>>> diffArray;
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            diffArray.push_back({abs(A[i] - A[j]), {A[i], A[j]}});
        }
    }
    return diffArray;
}

// find pair of elements that will give the difference eqaul to n
pair<int, int> findDiffPairs(int A[], int size, int n) {
    vector<pair<int, pair<int, int>>> diffA = findDiffArray(A, size);

    sort(diffA.begin(), diffA.end());
    int low = 0;
    int high = diffA.size() - 1;
    while(high - low > 1) {
        int mid = (low + high) / 2;
        if(diffA[mid].first <= n) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }

    if(diffA[low].first == n) {
        return diffA[low].second;  // if n found at low position
    } else if(diffA[high].first == n) {
        return diffA[high].second; // if n found at high position
    } else {
        // if no such pair exists then return INT_MIN as pairs
        pair<int, int> temp = {INT_MIN, INT_MIN};
        return temp;
    }
}

int main() {
    int n;
    cout << "Enter no. of elements: ";
    cin >> n;
    // take input int the array
    int A[n];
    cout << "Enter elements" << endl;
    for(int i = 0; i < n; ++i){
        cin >> A[i];
    }
    // given diff that would be searched
    int key;
    cout << "Enter the value: ";
    cin >> key;

    // find the required pair
    pair<int, int> result = findDiffPairs(A, n, key);
    
    if(result.first == INT_MIN && result.second == INT_MIN) {
        cout << "No such pair exists!" << endl;
    } else {
        cout << "The required pair is: ";
        cout << result.first << " " << result.second << endl;
    }
    return 0;
}