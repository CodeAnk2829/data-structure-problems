#include <bits/stdc++.h>
using namespace std;
int power(int n) {
    if(n & 1) {
        return 0;
    }
    int count = 0;
    count = 1 + power(n / 2);
    return count;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long long a[n];
        int b[n];
        int count2 = 0;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            b[i] = power(n - i);
            count2 += power(a[i]);
        }
        sort(b, b + n);
        if(n <= count2) {
            cout << 0 << endl;
        } else {
            int operations = 0;
            for(int i = n - 1; i >= 0; i--) {
                count2 += b[i];
                operations++;
                if(count2 >= n) {
                    break;
                }
            }
            if(count2 >= n) {
                cout << operations << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}