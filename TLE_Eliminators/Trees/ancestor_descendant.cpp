/*
    Given a rooted tree with n nodes and q queries for each query (x, y) check whether x is an ancestor of y or not
    n, q <= 1e5
*/

// T.C.- O(N*Q)

#include <bits/stdc++.h>
using namespace std;

void storeParent(vector<vector<int>>& adj, int currentNode, int parent, vector<int>& parentArray) {
    for (int neighbour : adj[currentNode]) {
        if (neighbour != parent) {
            parentArray[neighbour] = currentNode;
            storeParent(adj, neighbour, currentNode, parentArray);
        }
    }
}

bool checkDescendant(vector<vector<int>>& adj, int currentNode, int targetNode, int parent) {
    if (currentNode == targetNode) return true;
    bool isTargetNodeFound = false;

    for (int neighbour : adj[currentNode]) {
        if (neighbour != parent) {
            isTargetNodeFound |= checkDescendant(adj, neighbour, targetNode, currentNode);
        }
    }
    return isTargetNodeFound;
}

int main() {
    int n, q; 
    cin >> n >> q;
    
    // take input for nodes
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parentArray(n);
    storeParent(adj, 0, -1, parentArray);

    while(q--) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        bool isAncestor = checkDescendant(adj, x, y, parentArray[x]);

        if (isAncestor) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}