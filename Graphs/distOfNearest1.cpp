// TC = (N * M * 4);
#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int n, int m)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
    {
        return true;
    }
    return false;
}

void bfs(vector<vector<int>> &mat, queue<pair<int, int>> &q, vector<vector<int>> &vis, vector<vector<int>> &d)
{
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    int n = mat.size();
    int m = mat[0].size();

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if (isValid(nrow, ncol, n, m) && mat[nrow][ncol] == 0 && !vis[nrow][ncol])
            {
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
                d[nrow][ncol] = d[row][col] + 1;
            }
        }
    }
}
vector<vector<int>> nearest(vector<vector<int>> &mat, int n, int m)
{
    queue<pair<int, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> d(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {   
            // store coordinates of all ones in a queue
            // mark them as visited
            if (mat[i][j] == 1)
            {
                q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }

    // call to traverse the grid and find the distance
    bfs(mat, q, vis, d);

    return d;
}