#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;

const ll INF = 1e15;

vector<ll> dijkstra(int src, int n, vector<vector<pil>>& adj) {
    vector<ll> dist(n, INF);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    
    dist[src] = 0;
    pq.push({dist[src], src});

    while(!pq.empty()) {
        pair<ll, int> top = pq.top();
        pq.pop();

        int node = top.second;
        ll distSoFar = top.first;
        for(auto &i : adj[node]) {
            int neighbour = i.first;
            ll d = i.second;

            if(dist[neighbour] > distSoFar + d) {
                dist[neighbour] = distSoFar + d;
                pq.push({dist[neighbour], neighbour});
            }
        }
    }

    cout << "this is dist" << endl;
    for(auto d : dist) cout << d << " ";
    cout << endl;
    return dist;
}

int numOfClosedTrainRoutes(int src, int n, int k, vector<vector<pil>>& roads, map<int, vector<ll>>& trainRoutes) {
    vector<ll> dist = dijkstra(src, n, roads);
    int count = 0;

    
    for(auto route : trainRoutes) {
        cout << route.first << " -> ";

        ll currDistance = dist[route.first];
        cout << "CURR: " << currDistance << " -> ";
        for(auto dist: route.second) {
            cout << dist << " ";
            if(dist <= currDistance) {
                count++;
            }
        }
        cout << endl;
    }
    return count;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pil>> roads(n);
    ll minLength = INT_MAX;
    for(int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--, v--;
        roads[u].push_back({v, min(minLength, w)});
        roads[v].push_back({u, min(minLength, w)});
    }

    map<int, vector<ll>> trainRoutes;
    for(int i = 0; i < k; ++i) {
        int s;
        ll y;
        cin >> s >> y;
        s--;
        trainRoutes[s].push_back(y);
    }

    int result = numOfClosedTrainRoutes(0, n, k, roads, trainRoutes);
    cout << result << endl;
    return 0;
}