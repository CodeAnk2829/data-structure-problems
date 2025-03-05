#include <bits/stdc++.h>
using namespace std;
int n, m;
bool visited[1001][1001];

// movements in x direction
int dx[] = {-1, 0, 1, 0}; // {up, right, down, left}

// movements in y direction
int dy[] = {0, 1, 0, -1}; // {up, right, down, left}

bool isValid(int x, int y) {
    if(x < 1 || x > n || y < 1 || y > m) {
        return false;
    }
    if(visited[x][y] == true) {
        return false;
    }
    return true;
}

void dfs(int x, int y) {
    visited[x][y] = true;

    cout << x << " " << y << endl;

    // when direct path between the grids are considered 
    // only the common edges between two grids

    /*
    // Code 1-->Beginner

    if(isValid(x - 1, y)) {
        dfs(x - 1, y); // up
    }

    if(isValid(x, y + 1)) {
        dfs(x, y + 1); // right
    }

    if(isValid(x + 1, y)) {
        dfs(x + 1, y); // down
    }

    if(isValid(x, y - 1)) {
        dfs(x, y - 1); // left
    }
    */

   // Code 2
    for(int i = 0; i < 4; ++i) {
        if(isValid(x + dx[i], y + dy[i])) {
            dfs(x + dx[i], y + dy[i]);
        }
    }
}

int main() {
    cin >> n >> m;
    dfs(1, 1); // starting from row 1 and col 1
}