#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> arr(n);
    for(auto &i : arr) cin >> i;

    vector<int> mods(m, 0);
    for(auto num : arr) {
        mods[num % m]++;
    }

    // store the required remainder we need to calculate for 
    int remainder = -1;
    for(int i = 0; i < m; ++i) {
        if(mods[i] >= k) {
            remainder = i;
        }
    }

    if(remainder == -1) {
        cout << "No";
    } else {
        cout << "Yes" << endl;
        // check for the remainder obtained from previous step in the given array
        int count = 0;
        for(auto num : arr) {
            if(count >= k) break;
            if(num % m == remainder) {
                count++;
                cout << num << " ";
            }
        }
    }
    return 0;
}