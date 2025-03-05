#include <bits/stdc++.h>
using namespace std;
int maxDonuts(vector<int>& v) {
    sort(v.rbegin(), v.rend());
    int ans = 0;
    for(int i = 0; i < v.size(); ++i) {
        ans += (v[i] * pow(2, i));
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << maxDonuts(v) << endl;
    return 0;
}