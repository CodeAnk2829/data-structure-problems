// https://www.interviewbit.com/problems/path-in-directed-graph/
#include <bits/stdc++.h>
using namespace std;

// dfs traversal to find if there exists a path between 1 to A or not
int isFound(int s, vector<vector<int>>& adj, vector<int>& vis, int A) {
    if(s == A) return 1;

    vis[s] = 1;
    for(auto &node : adj[s]) {
        if(!vis[node]) {
            if(isFound(node, adj, vis, A)) return 1;
        }
    }
    return 0;
}

int solve(int A, vector<vector<int>> &B) {
    // create adjacency list
    vector<vector<int>> adj(A + 1);
    for (auto &b : B) {
        adj[b[0]].push_back(b[1]);
    }

    vector<int> vis(A + 1);
    return isFound(1, adj, vis, A);
}