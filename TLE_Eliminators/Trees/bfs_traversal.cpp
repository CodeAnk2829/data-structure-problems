// TC = O(N)

#include <bits/stdc++.h>
using namespace std;

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

    vector<int> bfsTraversal;

    int root = 0;
    queue<int> q;
    vector<bool> visited(n, false);
    q.push(root);
    visited[root] = true;

    while(!q.empty()) {
        int currentNode = q.front();
        q.pop();
        bfsTraversal.push_back(currentNode);
        for(int neighbour: adj[currentNode]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    for (int node : bfsTraversal) cout << node << " ";
    cout << endl;

    return 0;
}