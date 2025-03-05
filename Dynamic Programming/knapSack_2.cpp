// Method-2 Recursive approach for 0-1 knapSack problem
#include <bits/stdc++.h>
using namespace std;
int knapSack2(vector<int> wt, vector<int> val, int n, int w) {
    // Base case
    if(n == 0 || w == 0) {
        return 0;
    }

    // Choice diagram intusion
    if(wt[n - 1]  <= w) {
        return max(val[n - 1] + knapSack2(wt, val, n - 1, w - wt[n - 1]), knapSack2(wt, val, n - 1, w));
    } else {
        return knapSack2(wt, val, n - 1, w);
    }
}
int main() {
    int n, w;
    cin >> n >> w;

    vector<int> wt(n);
    for(int i = 0; i < n; ++i) cin >> wt[i];

    vector<int> val(n);
    for(int i = 0; i < n; ++i) cin >> val[i];

    int ans = knapSack2(wt, val, n, w);
    cout << ans << endl;
    return 0;
}