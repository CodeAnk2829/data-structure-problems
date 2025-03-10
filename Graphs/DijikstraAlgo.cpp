#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
vector<vector<pair<int, int>>> adj;

void dijikstraAlgo(int s, vector<int>& d, vector<int> p) {
    int n = adj.size();

    d.assign(n, INF);
    p.assign(n, -1);

    vector<bool> u(n, false);
    
    d[s] = 0;
    for(int i = 0; i < n; ++i) {
        int v = -1;
        for(int j = 0; j < n; ++j) {
            if(!u[j] && (v == -1 || d[j] < d[v])) {
                v = j;
            }
        }

        if(d[v] == INF) break;

        u[v] = true;

        for(auto &edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if(d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}

vector<int> restorePath(int s, int t, vector<int> const& p) {
    vector<int> path;
    
    for(int v = t; v != -1; v = p[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    return path;
}