#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> pil;

void Dijkstra(int src, int n, vector<vector<pil>>& edges, vector<ll>& dist) {
    vector<bool> marked(n, false);
    dist[src] = 0LL;
    set<pair<ll, int>> toExplore;
    toExplore.insert({0LL, src});
    while(toExplore.size() > 0) { 
        pair<ll, int> top = *toExplore.begin();
        toExplore.erase(top);

        int currNode = top.second;
        ll distSoFar = top.first;
        for(auto &neighbour : edges[currNode]) {
            int adjNode = neighbour.first;
            ll addedDist = neighbour.second;
            if(!marked[adjNode] && dist[adjNode] > distSoFar + addedDist) {
                toExplore.erase({dist[adjNode], adjNode});
                dist[adjNode] = distSoFar + addedDist;
                toExplore.insert({dist[adjNode], adjNode});
            }
        }
    }
}

int solve(int src, int n, vector<vector<pil>>& edges, vector<ll>& dist) {
    vector<bool> vis(n, false);
    dist[src] = 0LL;
    set<pair<ll, int>> s;
    s.insert({0LL, src});
    while(s.size() > 0) {
        pair<ll, int> front = *s.begin();
        s.erase(front);
        
        int currNode = front.second;
        ll minDistSoFar = front.first;
        vis[currNode] = true;

        for(auto neighbour: edges[currNode]) {
            int adjNode = neighbour.first;
            ll weight = neighbour.second;
        
            if(!vis[adjNode] && weight + minDistSoFar < dist[adjNode]) {
                s.erase({dist[adjNode], adjNode});
                dist[adjNode] = minDistSoFar + weight;
                s.insert({dist[adjNode], adjNode});
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<pil>> edges(n);
    for(int i = 0; i < e; ++i) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges[u].push_back({v, wt});
        edges[v].push_back({u, wt});
    }
    cout << "printed" << endl;
    vector<ll> dist(n);
    fill(dist.begin(), dist.end(), 1e18);

    Dijkstra(0, n, edges, dist);
    for(auto d : dist) cout << d << " ";
    cout << endl;
    return 0;
}