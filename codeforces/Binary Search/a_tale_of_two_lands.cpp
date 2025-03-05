#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        arr.push_back(abs(x));
    }
    sort(arr.begin(), arr.end());
    ll count = 0;
    for(int i = 0; i < n; ++i) {
        auto lbIterator = lower_bound(arr.begin(), arr.end(), (arr[i] + 1) / 2);
        int lbIndex = lbIterator - arr.begin();
        count += (ll)(i - lbIndex);
    }
    cout << count;

    return 0;
}