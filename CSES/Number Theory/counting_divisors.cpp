#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // precompute the divisors of all elements
    vector<int> divNums(1e6 + 1, 1);
    for(int i = 1e6; i >= 1; i--) {
        for(int j = i * 2; j <= 1e6; j += i) {
            divNums[j]++;
        }
    }

    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &i : arr) cin >> i;
    for(auto num : arr) {
        cout << divNums[num] << endl;
    }

    return 0;
}