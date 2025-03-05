// https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/A
#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<pair<double, double>>& arr, double time) {
    int n = arr.size();
    pair<double, double> intersection= {-1e18, 1e18};
    for(int i = 0; i < n; ++i) {
        pair<double, double> range = {arr[i].first - (arr[i].second * time), arr[i].first + (arr[i].second * time)};
        double x = max(intersection.first, range.first);
        double y = min(intersection.second, range.second);
        if(x > y) return false;
        intersection = {x, y};
    }
    
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<pair<double, double>> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }

    int iterations = 70;
    double low = 0, high = 1e9;

    for(int i = 0; i < iterations; ++i) {
        double mid = (low + high) / 2;
        if(isPossible(arr, mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    cout << setprecision(7) << fixed << high;
    return 0;
}