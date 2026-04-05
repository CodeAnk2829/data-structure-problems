/*
    Given a rooted tree with n nodes and q queries for each query (x, y) check whether x is an ancestor of y or not
    n, q <= 1e5
*/


#include <bits/stdc++.h>
using namespace std;

void calculateInOutTime(vector<vector<int>>& adj, int currentNode, int parent, int& currentTime, vector<int>& inTime, vector<int>& outTime) {
    inTime[currentNode] = currentTime++;
    for (int neighbour : adj[currentNode]) {
        if (neighbour != parent) {
            inTime[neighbour] = currentNode;
            calculateInOutTime(adj, neighbour, currentNode, currentTime, inTime, outTime);
        }
    }
    outTime[currentNode] = currentTime++;
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

    vector<int> inTime(n), outTime(n);
    int currentTime = 1;
    calculateInOutTime(adj, 0, -1, currentTime, inTime, outTime);

    // T.C.- O(1*Q) = O(Q)
    while(q--) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        bool isAncestor = (inTime[x] < inTime[y]) && (outTime[y] < outTime[x]);

        if (isAncestor) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}