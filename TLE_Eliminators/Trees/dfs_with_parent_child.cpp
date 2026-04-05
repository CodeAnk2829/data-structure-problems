
#include <bits/stdc++.h>
using namespace std;

void dfs(int currentNode, vector<vector<int>>& adj, vector<int>& ans) {
    ans.push_back(currentNode);
    for (int child: adj[currentNode]) {
        dfs(child, adj, ans);
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
        // store only the children of a node
        adj[u].push_back(v);
    }

    int root = 0;
    vector<int> dfsTraversal;

    dfs(root, adj, dfsTraversal);

    for (int node: dfsTraversal) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}