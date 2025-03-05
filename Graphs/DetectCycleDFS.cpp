// Sc : O(N) + O(N)
// TC : O(N) + O(N + 2E)
#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& adj, int s, int parent, vector<int>& vis) {
    vis[s] = 1;
    for(auto &adjacentNode : adj[s]) {
        if(!vis[adjacentNode]) {
            if(dfs(adj, adjacentNode, s, vis)) return true;
        } else if(parent != adjacentNode) { 
            return  true;
        }
    }

    return false;
}

bool detectCycle(vector<vector<int>>& adj, int V) {
    vector<int> vis(V, 0);
    for(int i = 0; i < V; ++i) {
        if(!vis[i]) {
            if(dfs(adj, i, -1, vis)) return true;
        }
    }
    return false;
}