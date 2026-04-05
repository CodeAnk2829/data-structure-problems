#include <bits/stdc++.h>
using namespace std;

#define nline "\n";

// degree of a node : it is defined as the maximum number of children assigned to any single node

void dfs(vector<vector<int>>& adj, int currentNode, int parent, vector<int>& degree) {
    int deg = 0;
    for (int neighbour : adj[currentNode]) {
        if (neighbour != parent) {
            deg++;
            dfs(adj, neighbour, currentNode, degree);
        }
    }
    degree[currentNode] = deg;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> deg(n);
    dfs(adj, 0, -1, deg);

    for (auto d : deg) {
        cout << d << " ";
    }
    cout << nline;
    
    return 0;
}