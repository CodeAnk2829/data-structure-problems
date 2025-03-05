#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int findMin(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp = matrix;

    for(int row = 1; row < n; ++row) {
        for(int col = 0; col < n; ++col) {
            int mini = INT_MAX;

            for(int i = -1; i <= 1; ++i) {
                int nrow = row - 1;
                int ncol = col + i;
                if(isValid(nrow, ncol, n)) {
                    mini = min(mini, dp[nrow][ncol]);
                }
            }

            int overHead = (mini != INT_MAX) ? mini : 0;
            dp[row][col] = overHead + matrix[row][col];
        }
    }
    
    int minVal = INT_MAX;
    for(int i = 0; i < n; ++i) {
        minVal = min(minVal, dp[n - 1][i]);
    }
    return minVal;
}