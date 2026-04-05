#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& adj, int currentNode, int parent, vector<int>& parentArray) {
    parentArray[currentNode] = parent;
    for (int child : adj[currentNode]) {
        if (child != parent) {
            dfs(adj, child, currentNode, parentArray);
        }
    }
}

void bfs(int n, vector<vector<int>>& adj, int root, vector<int>& parent) {
    queue<int> q;
    vector<bool> visited(n, false);
    q.push(root);
    visited[root] = true;
    parent[root] = -1;

    while(!q.empty()) {
        int currentNode = q.front();
        q.pop();

        for (int neighbour : adj[currentNode]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
                parent[neighbour] = currentNode;
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

    vector<int> parentArray(n);
    // dfs(adj, 0, -1, parentArray);
    bfs(n, adj, 0, parentArray);

    for (int node : parentArray)
        cout << node << " ";
    cout << endl;

    return 0;
}