// Maximum money looted by the robber using Dynammic Progarmming
// Time Comlexity = O(n)
// Space Complexity = O(n)
#include <iostream>
using namespace std;
int maximizeMoney(int* a, int n) {
    if(n == 1) {
        return a[0];
    }
    if(n == 2) {
        return max(a[0], a[1]);
    }
    int n = n;
    int* ans = new int[n];
    ans[0] = a[0];
    ans[1] = max(a[0], a[1]);
    for(int i = 2; i < n; ++i) {
        int temp1 = a[i] + ans[i - 2];
        int temp2 = ans[i - 1];
        ans[i] = max(temp1, temp2);
    }
    int result = ans[n - 1];
    delete [] ans;
    return result;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];
    cout << maximizeMoney(a, n);
    return 0;
}