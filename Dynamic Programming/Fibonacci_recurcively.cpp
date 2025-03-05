// Memoization (top-down approach) 
// Time Complexity = O(n)
#include <bits/stdc++.h>
using namespace std;
int fibonacci_helper(int n, int* ans) {
    if(n <= 1) {
        return n;
    }
    // Check if the output is already or not
    if(ans[n] != -1) {
        return ans[n];
    }
    int a = fibonacci_helper(n - 1, ans);
    int b = fibonacci_helper(n - 2, ans);

    // Save the output
    ans[n] = a + b;
    return ans[n];
}

int fibonacci2(int n) {
    int* ans = new int[n + 1];
    for(int i = 0; i <= n; ++i) {
        ans[i] = -1;
    }
    return fibonacci_helper(n, ans);
}
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << fibonacci2(n);
    return 0;
}