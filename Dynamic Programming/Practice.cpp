#include <bits/stdc++.h>
using namespace std;
int fibonacci(int n) {
    if(n <= 1) return n;
    int f1 = fibonacci(n - 1);
    int f2 = fibonacci(n - 2);
    int ans = f1 + f2;
    return ans;
}

int fibonacciMhelper(int n, int* ans) {
    if(n <= 1) return n;
    if(ans[n] != -1) {
        return ans[n];
    }
    int f1 = fibonacciMhelper(n - 1, ans);
    int f2 = fibonacciMhelper(n - 2, ans);
    ans[n] = f1 + f2;
    return ans[n];
}

int fibonacciM(int n)
{
    int* ans = new int[n + 1];
    for(int i = 0; i <= n; ++i) {
        ans[i] = -1;
    }
    int result = fibonacciMhelper(n, ans);
    delete [] ans;
    return result;
}
int fibonacciDP1(int n) {
    int* dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int ans = dp[n];
    delete [] dp;
    return ans;
}

int fibonacciDP2(int n) {
    if(n <= 1) {
        return n;
    }
    int dp0 = 0;
    int dp1 = 1;
    int ans = 0;
    for(int i = 2; i <= n; ++i) {
        ans = dp0 + dp1;
        dp0 = dp1;
        dp1 = ans;
    }
    return ans;
}

int minSteps(int n) {
    if(n == 1) return 0;
    int x = minSteps(n - 1);
    int y = INT_MAX, z = INT_MAX;
    if(n % 2 == 0) {
        y = minSteps(n / 2);
    }
    if(n % 3 == 0) {
        z = minSteps(n / 3);
    }
    int ans = 1 + min(x, min(y, z));
    return ans;
}

int minStepsMhelper(int n, int* ans) {
    if(n == 1) return 0;
    if(ans[n] != -1) {
        return ans[n];
    }
    int x = minSteps(n - 1);
    int y = INT_MAX, z = INT_MAX;
    if(n % 2 == 0) {
        y = minSteps(n / 2);
    }
    if(n % 3 == 0) {
        z = minSteps(n / 3);
    }
    ans[n] = 1 + min(x, min(y, z));
    return ans[n];
}

int minStepsM(int n) {
    int* ans = new int[n + 1];
    for(int i = 0; i <= n; ++i) {
        ans[i] = -1;
    }
    int result = minStepsMhelper(n, ans);
    delete [] ans;
    return result;
}

int minStepsDP1(int n) {
    if(n == 1) return 0;
    int* dp = new int[n + 1];
    dp[0] = dp[1] = 0;
    for(int i = 2; i <= n; ++i) {
        int x = dp[i - 1];
        int y = INT_MAX;
        int z = INT_MAX;
        if(i % 2 == 0) {
            y = dp[i / 2];
        }
        if(i % 3 == 0) {
            z = dp[i / 3];
        }
        dp[i] = 1 + min(x, min(y, z));
    }
    int ans = dp[n];
    delete [] dp;
    return ans;
}

int stairCase(int n) {
    if(n <= 2) return n;
    if(n == 3) return 4;
    int dp1 = 1, dp2 = 2, dp3 = 4;
    int ans;
    for(int i = 4; i <= n; ++i) {
        ans = dp1 + dp2 + dp3;
        dp1 = dp2; 
        dp2 = dp3;
        dp3 = ans;
    }
    return ans;
}

int minCount(int n) {
    if(n == 1) return 1;
    int ans = n;
    for(int i = 1; i * i <= n; ++i) {
        ans = min(ans, 1 + minCount(n - (i * i)));
    }
    return ans;
}

int minCountMhelper(int n, int* ans) {
    if(n == 0) return 0;
    if(ans[n] != -1) {
        return ans[n];
    }
    int temp = n;
    for(int i = 1; (i * i) <= n; ++i) {
        temp = min(temp, 1 + minCountMhelper(n - (i * i), ans));
    }
    ans[n] = temp;
    return ans[n];
}

int minCountM(int n) {
    int* ans = new int[n + 1];
    for(int i = 0; i <= n; ++i) {
        ans[i] = -1;
    }
    int result = minCountMhelper(n, ans);
    delete [] ans;
    return result;
}

int maxLoot(int* money, int n) {
    if(n <= 0) {
        return 0;
    }
    int option1 = money[n - 1] + maxLoot(money, n - 2);
    int option2 = maxLoot(money, n - 1);
    int ans = max(option1, option2);
    return ans;
}

int maxLootMhelper(int* money, int n, int* ans) {
    if(n <= 0) {
        return 0;
    }
    if(ans[n] != -1) {
        return ans[n];
    }
    int option1 = money[n - 1] + maxLootMhelper(money, n - 2, ans);
    int option2 = maxLootMhelper(money, n - 1, ans);
    ans[n] = max(option1, option2);
    return ans[n];
}

int maxLootM(int* money, int n) {
    int* ans = new int[n + 1];
    for(int i = 0; i <= n; ++i) {
        ans[i] = -1;
    }
    int result = maxLootMhelper(money, n, ans);
    delete [] ans;
    return result;
}

int maxLootDP(int* money, int n) {
    int* dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = money[0];
    for(int i = 2; i <= n; ++i) {
        int option1 = money[i - 1] + dp[i - 2];
        int option2 = dp[i - 1];
        dp[i] = max(option1, option2);
    }
    int ans = dp[n];
    delete [] dp;
    return ans;
}

int maxLootDP2(int* money, int n) {
    int dp0 = 0, dp1 = money[0];
    int ans;
    for(int i = 1; i < n; ++i) {
        int option1 = money[i] + dp0;
        int option2 = dp1;
        ans = max(option1, option2);
        dp0 = dp1;
        dp1 = ans;
    }
    return ans;
}

int LIS(int input[], int n) {
    int* output = new int[n];
    
    for(int i = 0; i < n; ++i) {
        output[i] = 1;
        for(int j = i - 1; j >= 0; j--) {
            if(input[j] < input[i]) {
                output[i] = max(output[i], 1 + output[j]);
            }
        }
    }
    int temp = output[0];
    for(int i = 0; i < n; ++i) {
        temp = max(temp, output[i]);
    }

    delete [] output;
    return temp;
}
int main() {
    int n;  
    cin >> n;
    cout << fibonacci(n) << endl;
    cout << fibonacciM(n) << endl;
    cout << fibonacciDP1(n) << endl;
    cout << fibonacciDP2(n) << endl;
    // cout << minSteps(n) << endl;
    // cout << minStepsDP1(n) << endl;
    // cout << minStepsM(n) << endl;
    // cout << stairCase(n) << endl;
    // cout << minCount(n) << endl;
    // cout << minCountM(n) << endl;
    // int arr[n];
    // for(int i = 0; i < n; ++i) {
    //     cin >> arr[i];
    // }
    // cout << maxLoot(arr, n) << endl;
    // cout << maxLootM(arr, n) << endl;
    // cout << maxLootDP(arr, n) << endl;
    // cout << maxLootDP2(arr, n) << endl;
    // cout << LIS(arr, n);
    return 0;
}