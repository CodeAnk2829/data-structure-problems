//Round-A 2021 K-Goodness String
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int j = 1; j <= t; ++j) {
        int n, k;
        cin >> n >> k;
        cin.ignore();
        char s[n + 1];
        cin.getline(s, n + 1);
        char ans[(n + 1)/2 + 1];
        for(int i = 0; i < (n + 1) / 2; ++i) {
            ans[i] = s[n - 1 - i];
        }
        ans[(n + 1) / 2] = '\0';
        int same = 0, diff = 0;
        for(int i = 0; i < (n + 1) / 2; ++i) {
            if(ans[i] == s[i]) {
                same++;
            } else {
                diff++;
            }
        }
        if(k <= diff) {
            cout << "Case #" << j << ": " << 0 << endl;
        } else {
            cout << "Case #" << j << ": " << (k - diff) << endl;
        }
    }
    return 0;
}