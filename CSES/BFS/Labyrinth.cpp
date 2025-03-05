#include <bits/stdc++.h>
using namespace std;

// movement in horizontal direction
int dx[] = {-1, 0, 1, 0}; // {up, right, down, left}

// movement in vertical direction
int dy[] = {0, 1, 0, -1}; // {up, right, down, left}

bool isValid(vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& visited) {
    int n = grid.size();
    int m = grid[0].size();

    if(x < 0 || x > (n - 1) || y < 0 || y > (m - 1)) {
        return false;
    }
    if((grid[x][y] == '.' || grid[x][y] == 'B') && visited[x][y]) {
        return false;
    }
    return true;
}

void bfs(vector<vector<char>>& grid, int srcX, int srcY, int destX, int destY, vector<vector<bool>>& visited, vector<vector<int>>& dist) {
    int n = grid.size();
    int m = grid[0].size();

    // parent array which stores pair of parent coordinates
    vector<vector<pair<int, int>>> p(n, vector<pair<int, int>>(m));
    p[srcX][srcY] = {-1, -1};

    visited[srcX][srcY] = true;

    queue<pair<int, int>> q;
    q.push({srcX, srcY});

    while(!q.empty()) {
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        // check for all possible movements i.e. {up, right, down, left}
      
        for(int i = 0; i < 4; ++i) {
            if (isValid(grid, currX + dx[i], currY + dy[i], visited) && (grid[currX + dx[i]][currY + dy[i]] == '.' || grid[currX + dx[i]][currY + dy[i]] == 'B'))
            {
                int newX = currX + dx[i];
                int newY = currY + dy[i];

                visited[newX][newY] = true;
                q.push({newX, newY});
                dist[newX][newY] = dist[currX][currY] + 1;
                p[newX][newY] = {currX, currY};
            }
        }
    }
    
   // find shortest path by the help of parent array

    if(!visited[destX][destY]) {
        cout << "NO";
    } else {
        string path;
        pair<int, int> parent;

        // find appropriate path
        for(int i = destX, j = destY; i != -1 && j != -1; i = parent.first, j = parent.second) {
            if(i == p[i][j].first) { // movement in horizontal direction
                if(j - p[i][j].second == -1) {
                    path.push_back('L');
                } else if(j - p[i][j].second == 1) {
                    path.push_back('R');
                }
            } else if(j == p[i][j].second) { // movement in vertical direction
                if(i - p[i][j].first == -1) {
                    path.push_back('U');
                } else if(i - p[i][j].first == 1) {
                    path.push_back('D');
                }
            } 
            parent = p[i][j];
        }
        
        reverse(path.begin(), path.end());

        // output
        cout << "YES" << endl;
        cout << dist[destX][destY] << endl;
        cout << path;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    int srcX, srcY;
    int destX, destY;

    // Take input
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if(grid[i][j] == 'A') {
                srcX = i;
                srcY = j;
            } else if(grid[i][j] == 'B') {
                destX = i;
                destY = j;
            }
        }
    }
    
    vector<vector<bool>> visited(n, vector<bool>(m));
    vector<vector<int>> dist(n, vector<int>(m));

    // find shortest path from A to B if exists
    bfs(grid, srcX, srcY, destX, destY, visited, dist);
    
    return 0;
}