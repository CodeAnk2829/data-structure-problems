#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto &i : arr) cin >> i;

        bool isPerfect = true;

        for(int i = 1; i < n; ++i) {
            int diff = abs(arr[i - 1] - arr[i]);
            if(diff != 5 && diff != 7) {
                isPerfect = false;
                break;
            }
        }

        if(isPerfect) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}