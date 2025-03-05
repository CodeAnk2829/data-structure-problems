#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> findPath(int s, int d, vector<int> &path)
    {
        if (path[d] == -1)
        {
            return {-1};
        }
        vector<int> ans;
        for (int i = d; i != -1; i = path[i])
        {
            ans.push_back(i);
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }

public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // create adjacency list
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto &e : edges)
        {
            int fv = e[0];
            int sv = e[1];
            int wt = e[2];
            adj[fv].push_back({sv, wt});
            adj[sv].push_back({fv, wt});
        }

        vector<int> dist(n + 1, 1e9);
        vector<int> path(n + 1, -1);

        dist[1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});

        while (!pq.empty())
        {
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            for (auto &it : adj[node])
            {
                int adjNode = it.first;
                int edgeWeight = it.second;
                if (d + edgeWeight < dist[adjNode])
                {
                    dist[adjNode] = d + edgeWeight;
                    path[adjNode] = node;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        vector<int> ans = findPath(1, n, path);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends