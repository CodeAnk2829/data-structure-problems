// To count the minimum no. of integers whose sum of squares equals the given n
// Brute force approach
#include <bits/stdc++.h>
using namespace std;
int minCount(int n) {
    if(n == 0) return 0;
    int ans = n;
    for(int i = 1; i * i <= n; ++i) {
        ans = min(ans, 1 + minCount(n - (i * i)));
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << minCount(n);
    return 0;
}