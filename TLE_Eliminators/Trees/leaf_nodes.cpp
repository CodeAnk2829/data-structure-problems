#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& adj, int currentNode, int parent) {
    int childrenCount = 0;
    int leafCounts = 0;
    for (int neighbour : adj[currentNode]) {
        if (neighbour != parent) {
            childrenCount++;
            leafCounts += dfs(adj, neighbour, currentNode);
        }
    }

    if (childrenCount == 0) return 1;
    return leafCounts;
}

int findLeafNodes(vector<vector<int>>& adj) {
    int leafCounts = 0;
    for (auto &node : adj) {
        if (node.size() == 1) 
            leafCounts++;
    }
    return leafCounts;
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

    int numLeafNodes = dfs(adj, 0, -1);
    cout << numLeafNodes << endl;
    cout << findLeafNodes(adj) << endl;

    return 0;
}