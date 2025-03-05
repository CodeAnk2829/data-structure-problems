// Problem Flood Fill Algorithm using dfs
#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int iniColor, int color, int dx[], int dy[]) {
    int n = image.size();
    int m = image[0].size();
    ans[row][col] = color;
    for (int i = 0; i < 4; ++i) {
        int nrow = row + dx[i];
        int ncol = col + dy[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != color) {
            dfs(nrow, ncol, ans, image, iniColor, color, dx, dy);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    vector<vector<int>> ans = image;
    int iniColor = image[sr][sc];
    int n = image.size();
    int m = image[0].size();

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    dfs(sr, sc, ans, image,iniColor, color, dx, dy);
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> image[i][j];
            }
        }
        int sr, sc, color;
        cin >> sr >> sc >> color;
        vector<vector<int>> ans = floodFill(image, sr, sc, color);
        for(auto &row : ans) {
            for(auto &col : row) {
                cout << col << " ";
            }
            cout << endl;
        }
    }
    return 0;
}