// problem link: https://codeforces.com/problemset/problem/25/D

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

class DisjointSet {
public: 
    vector<int> parent, size;

    DisjointSet(int n) {
        for(int i = 0; i <= n; ++i) {
            parent.push_back(i);
            size.push_back(1);
        }
    }

    int findParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionSize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n; 
    vector<pi> roads(n - 1);
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        roads[i] = {u, v};
    }

    DisjointSet d(n);
    int extraRoads = 0;
    vector<pi> roadsToBeClosed;

    for(auto &it : roads) {
        int u = it.first;
        int v = it.second;
        if(d.findParent(u) == d.findParent(v)) {
            extraRoads++;
            roadsToBeClosed.push_back({u, v});
        } else {
            d.unionSize(u, v);
        }
    }

    vector<int> components;
    for(int i = 1; i <= n; ++i) {
        if(d.parent[i] == i) {
            components.push_back(i);
        }
    }

    cout << extraRoads << endl;

    if(extraRoads != 0) {
        for(int i = 0; i < components.size() - 1; ++i) {
            cout << roadsToBeClosed[i].first << " " << roadsToBeClosed[i].second << " " << components[i] << " " << components[i + 1] << endl;
        }
    }
    return 0;
}