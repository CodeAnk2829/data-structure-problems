#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>

vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    vector<vector<pi>> adj(vertices);
    for(auto& e : edge) {
        int fv = e[0];
        int sv = e[1];
        int wt = e[2];
        adj[fv].push_back({sv, wt});
        adj[sv].push_back({fv, wt});
    }

    vector<int> dist(vertices, 1e9), vis(vertices, 0);
    dist[source] = 0;

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, source});

    while(!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // without the below if visited condition and mark the nodes as visited it will give TLE for some test cases
        // hence it is a good idea to always use this vis array
        if(vis[node]) {
            continue;
        }
        vis[node] = 1;

        for(auto& a : adj[node]) {
            int adjNode = a.first;
            int wt = a.second;
            if(d + wt < dist[adjNode]) {
                dist[adjNode] = d + wt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int main() {
    int t; 
    cin >> t;
    while(t--) {
        int v, e;
        cin >> v >> e;
        vector<vector<int>> edge;
        for(int i = 0; i < e; ++i) {
            int fv, sv, wt;
            cin >> fv >> sv >> wt;
            edge.push_back({fv, sv, wt});
        }
        vector<int> ans = dijkstra(edge, v, e, 0);
        for(auto &a : ans) {
            cout << a << " ";
        }
        cout << endl;
    }
    return 0;
}