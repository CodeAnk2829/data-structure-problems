#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, int currentNode, int parent, vector<int>& children) {
    int count = 0;
    for (int neighbour : adj[currentNode]) {
        if (neighbour != parent) {
            dfs(adj, neighbour, currentNode, children);
            count++;
        }
    }
    children[currentNode] = count;
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

    vector<int> childrenCount(n);
    dfs(adj, 0, -1, childrenCount);

    for (int cnt : childrenCount)
        cout << cnt << " ";
    cout << endl;

    return 0;
}