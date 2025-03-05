#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
const ll INF = 1e12;

vector<ll> dijkstra(int src, int dst, int n, vector<vector<pil>>& adj) {
    vector<ll> dist(n, INF), vis(n, 0);
    vector<int> parent(n, -1);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    
    dist[src] = 0;
    pq.push({dist[src], src});

    while(!pq.empty()) {
        pair<ll, int> top = pq.top();
        pq.pop();

        int node = top.second;
        ll distSoFar = top.first;

        // without this condition the same node that has been 
        // visited already will also be pushed to the priority
        // queue again and again leading to TLE for some test cases
        // hence it is always a good idea to mark the node when it is 
        // popped off the priority queue, it signifies that there will
        // not be any lesser distance than this distance
        if(vis[node]) continue;
        vis[node] = 1;

        for(auto &i : adj[node]) {
            int neighbour = i.first;
            ll d = i.second;

            if(dist[neighbour] > distSoFar + d) {
                dist[neighbour] = distSoFar + d;
                pq.push({dist[neighbour], neighbour});
                parent[neighbour] = node;
            }
        }
    }

    vector<ll> result;
    int node = dst;
    if(parent[node] == -1) {
        result.push_back(-1);
    } else {
        while(node != -1) {
            result.push_back(node + 1);
            node = parent[node];
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pil>> adj(n);

    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<ll> result = dijkstra(0, n - 1, n, adj);
    for(auto node : result) cout << node << " "; 
    return 0;
}