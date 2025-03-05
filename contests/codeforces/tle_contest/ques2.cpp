#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> arr(n - 1);
        for(auto &i : arr) cin >> i;

        vector<ll> result(n);
        result[0] = arr[0] + 1;

        for(int i = 1; i < n - 1; ++i)  {
            ll currSum = result[i - 1] + arr[i - 1];
            if(currSum <= arr[i]) {
                ll upperValue = (arr[i] + result[i - 1] - 1) / result[i - 1];
                result[i] = (upperValue * result[i - 1] + arr[i - 1]);
            } else {
                result[i] = result[i - 1] + arr[i - 1];
            }
        }
        result[n - 1] = result[n - 2] + arr.back();
        for(auto &element : result) cout << element << " ";
        cout << endl;
    }
    return 0;
}