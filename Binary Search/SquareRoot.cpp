#include <bits/stdc++.h>
using namespace std;

double eps = 1e-7;
int main() {
    double num;
    cin >> num;
    double lo = 0, hi = num;
    while(hi - lo > eps) {
        double mid = (lo + hi) / 2;
        if(mid * mid < num) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << lo << endl;
    return 0;
}