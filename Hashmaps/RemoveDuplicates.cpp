// Program to remove duplicate elements from the given array
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> removeDuplicate(int* arr, int size) {
    vector<int> output;
    unordered_map<int, bool> seen;
    for(int i = 0; i < size; ++i) {
        if(seen.count(arr[i]) > 0) {
            continue;
        }
        seen[arr[i]] = true;
        output.push_back(arr[i]);
    }
    return output;
}

int main() {
    int arr[] = {2, 1, 3, 2, 1, 4, 5, 2, 3, 1, 4, 5, 6};
    int n = sizeof(arr) / 4;
    vector<int> output = removeDuplicate(arr, n);
    for(int i = 0; i < output.size(); ++i) {
        cout << output[i] << endl;
    }
    return 0;
}