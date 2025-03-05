#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent, size;

public:
    DSU(int n) {
        for (int i = 0; i < n; ++i) {
            parent.push_back(i);
            size.push_back(1);
        }
    }

    int findParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionSize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

int spanningTree(int V, vector<vector<int>> adj[])
{
    // store the edges and weights in the form of {wt, {u, v}}
    vector<pair<int, pair<int, int>>> edges;
    vector<int> visited(V, 0);

    for (int it = 0; it < V; ++it) {
        visited[it] = 1;
        for (auto i : adj[it]) {
            if (!visited[i[0]]) {
                int u = it;
                int v = i[0];
                int wt = i[1];
                edges.push_back({wt, {u, v}});
            }
        }
    }

    sort(edges.begin(), edges.end());

    DSU d(V);
    int mstSum = 0;

    for (auto it : edges) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if (d.findParent(u) != d.findParent(v)) {
            mstSum += wt;
            d.unionSize(u, v);
        }
    }

    return mstSum;
}