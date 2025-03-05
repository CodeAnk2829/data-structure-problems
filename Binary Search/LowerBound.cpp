// Program to find the lower bound for the given key using binary search
#include <bits/stdc++.h>
using namespace std;
int lower_bound(vector<int> &v, int key) {
    int lo = 0, hi = v.size() - 1;
    int ans = v.size();
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if(v[mid] >= key) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
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
    int lb = lower_bound(v, key);
    cout << lb << endl;
    return 0;
}