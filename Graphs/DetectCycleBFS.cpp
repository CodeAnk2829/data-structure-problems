#include <bits/stdc++.h>
using namespace std;

// detect cycle using bfs
bool detect(int s, vector<int> adj[], vector<int> &vis)
{
    vis[s] = true;
    queue<pair<int, int>> q;
    q.push({s, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto &u : adj[node])
        {
            if (!vis[u])
            {
                vis[u] = true;
                q.push({u, node});
            }
            else if (parent != u)
            {
                return true;
            }
        }
    }
    return false;
}

// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[])
{
    // Code here
    vector<int> vis(V);
    for (int i = 0; i < V; ++i)
    {
        if (!vis[i])
        {
            if (detect(i, adj, vis))
            {
                return true;
            }
        }
    }
    return false;
}

//{ Driver Code Starts.
int main()
{
int tc;
cin >> tc;
while (tc--)
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
}
return 0;
}