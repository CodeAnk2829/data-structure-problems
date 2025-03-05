#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    int pos = 1;
    for(int i = 31; i >= 0; i--) {
        if((1 << i) & n) {
            pos = i;
            break;
        }
    }
    pos++;
    int ans = (1 << pos) - 2;
    return ans;
}

int main() {
    int n; 
    cin >> n;

    int result = solve(n);
    cout << result << endl;
    return 0;
}