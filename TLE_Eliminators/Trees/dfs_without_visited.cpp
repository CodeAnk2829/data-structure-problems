// TC = O(N)
#include <bits/stdc++.h>
using namespace std;

void dfs(int currentNode, vector<vector<int>>& adj, int parent, vector<int>& ans) {
    ans.push_back(currentNode);
    for (int neighbour: adj[currentNode]) {
        if (neighbour != parent)
            dfs(neighbour, adj, currentNode, ans);
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
    int root = 0;
    dfs(root, adj, -1, dfsTraversal);

    for (int node: dfsTraversal) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}