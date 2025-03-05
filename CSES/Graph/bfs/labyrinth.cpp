#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}


bool bfs(pair<int, int>& start, vector<vector<bool>>& vis, vector<vector<pair<int, int>>>& parent, vector<vector<char>>& grid) {
    int sr = start.first;
    int sc = start.second;
    int n = grid.size();
    int m = grid[0].size();

    vis[sr][sc] = true;
    
    queue<pair<int, int>> q;
    q.push({sr, sc});
    while(!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();

        int row = front.first;
        int col = front.second;

        for(int i = 0; i < 4; ++i) {
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if(isValid(nrow, ncol, n, m) && !vis[nrow][ncol]) {
                if (grid[nrow][ncol] == '.') {
                    vis[nrow][ncol] = true;
                    q.push({nrow, ncol});
                    parent[nrow][ncol] = {row, col};
                } else if(grid[nrow][ncol] == 'B') {
                    parent[nrow][ncol] = {row, col};
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    
    pair<int, int> start, end;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] == 'A') {
                start = {i, j};
            } else if(grid[i][j] == 'B') {
                end = {i, j};
            }
        }
    }

    bool result = bfs(start, visited, parent, grid);
    if(result == false) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;

        // find path
        string path;
        int distance = 0;
        int row = end.first;
        int col = end.second;

        while(grid[row][col] != 'A') {
            pair<int, int> p = parent[row][col];
            if(p.first - row == -1) {
                path.push_back('D');
            } else if(p.first - row == 1) {
                path.push_back('U');
            } else if(p.second - col == -1) {
                path.push_back('R');
            } else if(p.second - col == 1) {
                path.push_back('L');
            }
            distance++;
            row = p.first;
            col = p.second;
        }

        reverse(path.begin(), path.end());
        cout << distance << endl;
        cout << path << endl;
    }

    return 0;
}