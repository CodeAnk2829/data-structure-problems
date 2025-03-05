#include <bits/stdc++.h>
using namespace std;

// movement in horizontal direction
int dx[] = {-1, 0, 1, 0};

// movement in vertical direction
int dy[] = {0, 1, 0, -1};

bool isValid(vector<vector<char>>& buildingMap, int x, int y, vector<vector<bool>>& visited) {
    int n = buildingMap.size();
    int m = buildingMap[0].size();

    if(x < 0 || x > (n - 1) || y < 0 || y >(m - 1)) {
        return false;
    }

    if(buildingMap[x][y] == '.' && visited[x][y] == true) {
        return false;
    }
    return true;
}

void bfs(vector<vector<char>>& buildingMap, int srcX, int srcY, vector<vector<bool>>& visited) {
    visited[srcX][srcY] = true;

    queue<pair<int, int>> q;
    q.push({srcX, srcY});

    while(!q.empty()) {
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        for(int i = 0; i < 4; ++i) {
            if(isValid(buildingMap, currX + dx[i], currY + dy[i], visited) && buildingMap[currX + dx[i]][currY + dy[i]] == '.') {
                int newX = currX + dx[i];
                int newY = currY + dy[i];

                q.push({newX, newY});
                visited[newX][newY] = true;
            }
        }
    }
}

int countRooms(vector<vector<char>>& buildingMap) {
    int n = buildingMap.size();
    int m = buildingMap[0].size();
    int ctRooms = 0;

    vector<vector<bool>> visited(n, vector<bool>(m));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(buildingMap[i][j] == '.' && visited[i][j] == false) {
                ctRooms++;
                bfs(buildingMap, i, j, visited);
            }
        }
    }

    return ctRooms;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    // Take input
    vector<vector<char>> buildingMap(n, vector<char>(m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> buildingMap[i][j];
        }
    }

    // count the no. of rooms in the buildingMap
    int res = countRooms(buildingMap);
    cout << res;
    return 0;
}
