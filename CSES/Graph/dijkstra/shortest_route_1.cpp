#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll INF = 1e18;

vector<ll> findShortestRoute(ll n, ll m, vector<vector<pll>>& routes) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vector<ll> dist(n, INF), vis(n, 0);
    dist[0] = 0LL;
    pq.push({dist[0], 0});
    
    while(!pq.empty()) {
        pll top = pq.top();
        pq.pop();

        ll currNode = top.second;
        ll distSoFar = top.first;

        // without the below if visited condition and mark the nodes as visited it will give TLE for some test cases
        // hence it is a good idea to always use this vis array
        if(vis[currNode]) {
            continue;
        }
        vis[currNode] = 1;

        for(auto &node : routes[currNode]) {
            ll neighbour = node.first;
            ll d = node.second;

            if(dist[neighbour] > distSoFar + d) {
                dist[neighbour] = distSoFar + d;
                pq.push({dist[neighbour], neighbour});
            }
        }
    }

    return dist;
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<pll>> routes(n);
    for(ll i = 0; i < m; ++i) {
        ll src, dst, length;
        cin >> src >> dst >> length;
        --src, --dst;
        routes[src].push_back({dst, length});
    }

    vector<ll> result = findShortestRoute(n, m, routes);
    for(auto &it : result) {
        cout << it << " ";
    }
    return 0;
}