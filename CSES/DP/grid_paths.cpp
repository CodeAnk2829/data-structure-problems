#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

/*
    state: f(i, j) --> number of paths from (i, j) to (n - 1, n - 1) with only empty cells
    transition: f(i, j) --> f(i + 1, j) + f(i, j + 1)
*/

int helper(int n, vector<vector<char>>& grid, int i, int j, vector<vector<int>>& dp) {
    // base case
    if(i == n - 1 && j == n - 1 && grid[i][j] != '*') return 1;
    if(i >= n || j >= n) return 0;
    if(grid[i][j] == '*') return 0;
    
    // if ans previously calculated
    if(dp[i][j] != -1) return dp[i][j];

    int moveRight = helper(n, grid, i, j + 1, dp);
    int moveDown = helper(n, grid, i + 1, j, dp);

    return dp[i][j] = (moveRight + moveDown) % mod;
}

int findGridPaths(int n, vector<vector<char>>& grid) {
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return helper(n, grid, 0, 0, dp);
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for(auto &row : grid) {
        for(auto &j : row) {
            cin >> j;
        }
    }

    cout << findGridPaths(n, grid) << endl;
    return 0;
}