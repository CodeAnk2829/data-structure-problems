// Program to find the upper bound of given number using binary search
#include <bits/stdc++.h>
using namespace std;
int upper_bound(vector<int> &v, int key) {
    int low = 0, high = v.size() - 1;
    int ans = v.size();
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(v[mid] > key) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int key;
    cin >> key;
    int ub = upper_bound(v, key);
    cout << ub;
    return 0;
}