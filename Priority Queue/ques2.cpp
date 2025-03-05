#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 3, 5, 8};
    int index = lower_bound(arr.begin(), arr.end(), 3) - arr.begin() - 1;
    cout << index << endl;
    return 0;
}