#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int source, int marker, vector<bool>& vis, vector<int>& parent, vector<vector<int>>& graph) {
        vis[source] = true;
        for(auto neighbour : graph[source]) {
            if(!vis[neighbour]) {
                parent[neighbour] = source;
                dfs(neighbour, 1 - marker, vis, parent, graph);
            } else if(marker == parent[source]) {
                return false;
            }
        }
        return true;
    }

public: 
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<int> parent(n, -1);
        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                if(dfs(i, 0, visited, parent, graph) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};