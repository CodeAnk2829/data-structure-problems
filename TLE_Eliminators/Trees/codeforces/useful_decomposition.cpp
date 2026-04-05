// https://codeforces.com/problemset/problem/981/C

#include <bits/stdc++.h>
using namespace std;

#define nline '\n';
vector<int> leafs;

void dfs(vector<vector<int>>& adj, int currentNode, int parent) {
    int deg = 0;
    for (int neighbour : adj[currentNode]) {
        if (neighbour != parent) {
            deg++;
            dfs(adj, neighbour, currentNode);
        }
    }
    if (0 == deg) {
        leafs.push_back(currentNode);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int countDegGreaterThan2 = 0;
    int possibleRoot = 0;

    for (int i = 0; i < n; i++) {
        if (2 < (int)adj[i].size()) {
            countDegGreaterThan2++;
            possibleRoot = i;
        }
    }

    if (countDegGreaterThan2 > 1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        dfs(adj, possibleRoot, -1);

        cout << (int)leafs.size() << nline;
        for (int i = 0; i < (int)leafs.size(); i++) {
            cout << (possibleRoot + 1) << " " << (leafs[i] + 1) << nline;
        }
    }

    return 0;
}