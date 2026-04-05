#include <bits/stdc++.h>
using namespace std;

void dfs(int currentNode, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ans) {
    ans.push_back(currentNode);
    vis[currentNode] = true;

    for (int neighbour: adj[currentNode]) {
        if (vis[neighbour]) continue;
        dfs(neighbour, adj, vis, ans);
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

    vector<int> dfsTraversal;
    vector<int> visited(n, false);
    int root = 0;
    dfs(root, adj, visited, dfsTraversal);

    for (int node: dfsTraversal) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}