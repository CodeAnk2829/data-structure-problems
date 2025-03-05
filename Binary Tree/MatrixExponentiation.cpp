#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> multiplyMatrices(vector<vector<int>> a, vector<vector<int>> b) {
    const int mod = 1e9 + 7;
    vector<vector<int>> ans(2, vector<int>(2, 0));

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                ans[i][k] = (ans[i][k] + (long long)((long long)a[i][j] * (long long)b[j][k])) % mod;
            }
        }
    }
    
    return ans;
}

vector<vector<int>> powOfMatrix(vector<vector<int>> M, int n) {
    vector<vector<int>> res = {{1, 0}, {0, 1}};

    while (n > 0) {
        if (n & 1) {
            res = multiplyMatrices(res, M);
        }
        M = multiplyMatrices(M, M);
        n >>= 1;
    }

    return res;
}

int fibonacciNumber(int n) {
    vector<vector<int>> coeff = {{1, 1}, {1, 0}};

    vector<vector<int>> res = powOfMatrix(coeff, n - 1);

    int ans = res[0][0];

    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << fibonacciNumber(n) << endl;
    return 0;
}