#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll INF = 1e18;

ll findMinimumCostAfterFlightDiscount(ll n, vector<vector<pll>>& routes) {
    vector<ll> price(n + 1, INF), vis(n + 1, 0), parent(n + 1, -1);
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    price[1] = 0LL;
    pq.push({price[1], 1});

    while(!pq.empty()) {
        pll top = pq.top();
        pq.pop();

        ll currNode = top.second;
        ll priceSoFar = top.first;

        if(vis[currNode]) continue;
        vis[currNode] = 1;

        for(auto &route : routes[currNode]) {
            ll neighbour = route.first;
            ll cost = route.second;

            if(price[neighbour] > priceSoFar + cost) {
                price[neighbour] = priceSoFar + cost;
                pq.push({price[neighbour], neighbour});
                parent[neighbour] = currNode;
            }
        }
    }   

    ll maxPriceDuringFlight = 0LL;
    ll node = n;
    while(node != 1) {
        ll diff = abs(price[node] - price[parent[node]]);
        maxPriceDuringFlight = max(maxPriceDuringFlight, diff);
        node = parent[node];
    }

    int discount = maxPriceDuringFlight - maxPriceDuringFlight / 2;
    return price[n];
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<pll>> routes(n + 1);
    for(int i = 0; i < m; ++i) {
        ll u, v, cost;
        cin >> u >> v >> cost;
        routes[u].push_back({v, cost});
    }

    ll result = findMinimumCostAfterFlightDiscount(n, routes);
    cout << result << endl;
    return 0;
}