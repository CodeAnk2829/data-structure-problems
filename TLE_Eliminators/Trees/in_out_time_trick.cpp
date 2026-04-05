#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, int currentNode, int parent, vector<int>& inTime, vector<int>& outTime, int& currentTime) {
    inTime[currentNode] = currentTime++;
    for (int neighbour : adj[currentNode]) {
        if (neighbour != parent) {
            dfs(adj, neighbour, currentNode, inTime, outTime, currentTime);
        }
    }
    outTime[currentNode] = currentTime++;
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

    vector<int> inTime(n), outTime(n);
    int currentTime = 1;

    dfs(adj, 0, -1, inTime, outTime, currentTime);

    for (int t : inTime) 
        cout << t << " ";
    cout << endl;

    for (int t : outTime) 
        cout << t << " ";
    cout << endl;

    return 0;
}