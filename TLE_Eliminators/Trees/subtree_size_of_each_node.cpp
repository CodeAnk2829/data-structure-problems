#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, int currentNode, int parent, vector<int>& subSizes) {
    subSizes[currentNode] = 1;
    for (int neighbour : adj[currentNode]) {
        if (neighbour != parent) {
            dfs(adj, neighbour, currentNode, subSizes);
            subSizes[currentNode] += subSizes[neighbour];
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

    vector<int> subtreeSizes(n);
    dfs(adj, 0, -1, subtreeSizes);

    for (int size : subtreeSizes)
        cout << size << " ";
    cout << endl;

    return 0;
}