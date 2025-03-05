#include <bits/stdc++.h>
using namespace std;
int orangeRottening(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    queue<pair<pair<int, int>, int>> q;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] == 2) {
                q.push({{i,  j}, 0});
                vis[i][j] = 2;
            }
        }
    }
    
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    int time = 0;
    
    while(!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int t = q.front().second;
        time = max(time, t);
        q.pop();

        // check for all four directions
        for(int i = 0; i < 4; ++i) {
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
            && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2) {
                vis[nrow][ncol] = 2;
                q.push({{nrow, ncol}, t + 1});
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] == 1 && vis[i][j] != 2) {
                return -1;
            }
        }
    }

    return time;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> oranges(n, vector<int>(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> oranges[i][j];
            }
        }
        cout << orangeRottening(oranges) << endl;
    }
    return 0;
}