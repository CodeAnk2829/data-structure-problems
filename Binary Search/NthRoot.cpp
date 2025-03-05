#include <bits/stdc++.h>
using namespace std;
double eps = 1e-6;
double multipy(double m, int n) {
    double ans = 1;
    for(int i = 0; i < n; ++i) ans *= m;
    return ans;
}
int main() {
    double n;
    int exp;
    cin >> n >> exp;
    double lo = 1;
    double hi = n;
    while(hi - lo > eps) {
        double mid = (lo + hi) / 2;
        if(multipy(mid, exp) < n) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << lo;
    return 0;
}