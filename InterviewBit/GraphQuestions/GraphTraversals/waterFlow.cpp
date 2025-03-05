// https://leetcode.com/problems/pacific-atlantic-water-flow/
#include <bits/stdc++.h>
using namespace std;


bool isValid(int x, int y, int n, int m) {
    if(x >= 0 && x < n && y >= 0 && y < m) return true;
    return false;
}

void bfs(vector<vector<int>> &heights, vector<vector<int>>& ocean, queue<pair<int, int>>& q) {
    int n = heights.size();
    int m = heights[0].size();

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i = 0; i < 4; ++i) {
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if(isValid(nrow, ncol, n, m) && ocean[nrow][ncol] == 0 && heights[nrow][ncol] >= heights[row][col]) {
                q.push({nrow, ncol});
                ocean[nrow][ncol] = 1;
            }
        }
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();

    queue<pair<int, int>> q;

    vector<vector<int>> pacOcean(n, vector<int>(m, 0));
    // mark all continents as visited which are adjacent to pacific ocean
    for(int i = 0; i < m; ++i) {
        q.push({0, i});
        pacOcean[0][i] = 1;
    }
    for(int i = 1; i < n; ++i) {
        q.push({i, 0});
        pacOcean[i][0] = 1;
    }

    // find all continents from where Pacific ocean is reachable
    bfs(heights, pacOcean, q);

    vector<vector<int>> atlOcean(n, vector<int>(m, 0));
    // mark all continents as visited which are adjacent to atlantic ocean
    for(int i = 0; i < n; ++i) {
        q.push({i, m - 1});
        atlOcean[i][m - 1] = 1;
    }
    for(int i = 0; i < m - 1; ++i) {
        q.push({n - 1, i});
        atlOcean[n - 1][i] = 1;
    }

    // find all continents from where Atlantic ocean is reachable
    bfs(heights, atlOcean, q);

    // find the indices of the continents from where both oceans are reachable
    vector<vector<int>> ans;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(pacOcean[i][j] == 1 && atlOcean[i][j] == 1) {
                vector<int> temp(2);
                temp[0] = i;
                temp[1] = j;
                ans.push_back(temp);
            }
        }
    }

    return ans;
}
