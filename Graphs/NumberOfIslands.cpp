// Find the number of islands 
#include <bits/stdc++.h>
using namespace std;

void bfs(int row, int col, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &vis)
{
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});

    while (!q.empty())
    {
        int currRow = q.front().first;
        int currCol = q.front().second;
        q.pop();

        for (int delRow = -1; delRow <= 1; delRow++)
        {
            for (int delCol = -1; delCol <= 1; delCol++)
            {
                int nrow = currRow + delRow;
                int ncol = currCol + delCol;

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0)
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
}
// Function to find the number of islands.
int numIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < m; ++col)
        {
            if (grid[row][col] == 1 && vis[row][col] == 0)
            {
                bfs(row, col, n, m, grid, vis);
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for(int i = 0; i < n; ++i) {
            vector<int> temp;
            for(int j = 0; j < m; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        cout << numIslands(grid);
    }
    return 0;
}