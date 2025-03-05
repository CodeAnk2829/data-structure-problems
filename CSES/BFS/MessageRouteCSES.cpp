#include <bits/stdc++.h>
using namespace std;
void findRoute(vector<vector<int>>& edges) {
    int n = edges.size() - 1; // no. of vertices
    int s = 1;            // Uolevi's computer
    int d = n;            // Maija's computer

    vector<bool> used(n + 1);
    vector<int> dist(n + 1), parent(n + 1);
    
    queue<int> q;
    q.push(s);
    parent[s] = -1;
    used[s] = true;

    // calculate shortest path and distances
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int u : edges[v]) {
            if(!used[u]) {
                used[u] = true;
                q.push(u);
                dist[u] = dist[v] + 1;
                parent[u] = v;
            }
        }
    }

    // print route if exists
    if(!used[d]) {
        cout << "IMPOSSIBLE";
    } else {
        vector<int> route;
        for(int v = d; v != -1; v = parent[v]) {
            route.push_back(v);
        }
        reverse(route.begin(), route.end());
        cout << dist[d] + 1 << endl;
        for(auto &path : route) {
            cout << path << " ";
        }
    }
}
int main() {
    int n, e;
    cin >> n >> e;
    map<int, vector<int>> m;
    m[0] = {0};
    for(int i = 0; i < e; ++i) {
        int fv, sv;
        cin >> fv >> sv;
        m[fv].push_back(sv);
        m[sv].push_back(fv);
    }
    
    vector<vector<int>> edges(n + 1);
    for(auto &x : m) {
        edges[x.first] = (x.second);
    }
    
    // find message route
    findRoute(edges);
    return 0;
}