// problem link: https://codeforces.com/edu/course/2/lesson/6/4/practice/contest/285069/problem/C

#include <bits/stdc++.h>
using namespace std;

bool isPossible(double x, vector<double>& a, vector<double>& b, int n, int k) {
    vector<double> transformedArr(n);
    for(int i = 0; i < n; ++i) {
        transformedArr[i] = a[i] - (b[i] * x);
    }
    sort(transformedArr.begin(), transformedArr.end(), [&](double first, double second) -> bool {
        return first > second;
    });
    double sum = 0;

    for(int i = 0; i < k; ++i) {
        sum += transformedArr[i];
    }
    return sum >= 0;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<double> a(n), b(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    double low = 0, high = 1e10;
    int iterations = 60;
    for(int i = 0; i < iterations; ++i) {
        double mid  = (high + low) / 2;
        if(isPossible(mid, a, b, n, k)) {
            low = mid;
        } else {
            high = mid;
        }
    }
    cout << setprecision(7) << fixed << low << endl;
    return 0;
}