#include <bits/stdc++.h>
using namespace std;
int n, m;
int dist[1000][1000];
int visited[1000][1000];

// valid movements in x directions
int dx[] = {-1, 0, 1, 0}; // {up, right, down, left}

// valid movements in y directions
int dy[] = {0, 1, 0, -1}; // {up, right, down, left}

bool isValid(int x, int y) {
    if(x < 0 || x > (n - 1) || y < 0 || y > (m - 1)) {
        return false;
    }

    if(visited[x][y] == true) {
        return false;
    }

    return true;
}

void bfs(int srcX, int srcY) {
    cout << "Ankit" << endl;
    visited[srcX][srcY] = true;
    dist[srcX][srcY] = 0;

    queue<pair<int, int>> q;
    q.push({srcX, srcY});   
    
    while(!q.empty()) {
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        for(int i = 0; i < 4; ++i) {
            int newX = currX + dx[i];
            int newY = currY + dy[i];

            if(isValid(newX, newY)) {
                visited[newX][newY] = true;
                q.push({newX, newY});
                dist[newX][newY] = dist[currX][currY] + 1;
            }
        }
    }
    cout << "Hello" << endl;
    // print distance array
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cin >> n >> m;
    int srcX, srcY;
    cin >> srcX >> srcY;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            visited[i][j] = false;
        }
    }

    bfs(srcX, srcY);
    return 0;
}