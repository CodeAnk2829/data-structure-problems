#include <bits/stdc++.h>
using namespace std;

// Function to traverse the across the connect cities
void dfs(vector<vector<int>>& adj, int s, vector<bool>& vis) {
    vis[s] = true;
    for(auto &u : adj[s]) {
        if(!vis[u]) {
            dfs(adj, u, vis);
        }
    }
}

void buildingRoads(vector<pair<int, int>>& edges, int v) {
    // Make adjacency list from vector of pairs
    vector<vector<int>> adj(v + 1);
    for(auto &e : edges) {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }

    int count = 0;
    vector<int> ans;

    vector<bool> vis(v + 1);
    
    for(int i = 1; i <= v; ++i) {
        if(!vis[i]) {
            // store the starting nodes every time
            ans.push_back(i); 

            // count the number of connected components
            count++;

            dfs(adj, i, vis);
        }
    }

    // print result
    cout << count - 1 << endl;
    for(int i = 0; i < count - 1; i++) {
        cout << ans[i] << " " << ans[i + 1] << endl;
    }
}

int main() {
    int v, e;
    cin >> v >> e;

    // Take input
    vector<pair<int, int>> edges;
    for(int i = 0; i < e; ++i) {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
    }
    
    // find and print the ans
    buildingRoads(edges, v);
    return 0;
}