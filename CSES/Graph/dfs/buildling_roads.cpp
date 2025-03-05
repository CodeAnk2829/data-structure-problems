#include <bits/stdc++.h>
using namespace std;

void dfs(int source, vector<bool>& vis, vector<vector<int>>& edges) {
    vis[source] = true;
    for(auto &neighbour : edges[source]) {
        if(!vis[neighbour]) {
            dfs(neighbour, vis, edges);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n);
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    
    vector<bool> visited(n, false);
    int count = 0;
    vector<int> origins;

    for(int i = 0; i < n; ++i) {
        if(!visited[i]) {
            dfs(i, visited, edges);
            count++;
            origins.push_back(i + 1);
        }
    }

    cout << count - 1 << endl;
    for(int i = 0; i < count - 1; ++i) {
        cout << origins[i] << " " << origins[i + 1] << endl;
    }
    return 0;
}