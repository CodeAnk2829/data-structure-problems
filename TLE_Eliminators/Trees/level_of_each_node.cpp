#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, int currentNode, int parent, int currentLevel, vector<int>& level) {
    level[currentNode] = currentLevel;

    for (int neighbour : adj[currentNode]) {
        if (neighbour != parent) {
            dfs(adj, neighbour, currentNode, currentLevel + 1, level);
        }
    }
}

void bfs(int n, vector<vector<int>>& adj, int root, vector<int>& level) {
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(root);
    visited[root] = true;
    level[root] = 0;

    while(!q.empty()) {
        int currentNode = q.front();
        q.pop();
        
        for (int neighbour : adj[currentNode]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
                level[neighbour] = level[currentNode] + 1;
            }
        }
    }
}

int main() {
    int n; 
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> levelOfEachNode(n);

    // dfs(adj, 0, -1, 0, levelOfEachNode);
    bfs(n, adj, 0, levelOfEachNode);

    for (int level : levelOfEachNode)
        cout << level << " ";
    cout << endl;

    return 0;
}