// https://codeforces.com/problemset/problem/913/B

#include <bits/stdc++.h>
        using namespace std;

void markLeafs(int n, vector<vector<int>>& adj, vector<bool>& leafs) {
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1) {
            leafs[i] = true;
        }
    }
}

void solve(int n, vector<int>& parentIndex) {
    vector<vector<int>> adj(n + 1);
    int v = 1;
    for (int i = 0; i < n - 1; i++, v++) {
        adj[v + 1].push_back(parentIndex[i]);
        adj[parentIndex[i]].push_back(v + 1);
    }

    vector<bool> leafs(n + 1, false);
    markLeafs(n, adj, leafs);
    bool isSpruce = true;

    for (int i = 1; i <= n; i++) {
        // choose non-leafs
        if (!leafs[i]) {
            int leafCount = 0;
            for (int neighbour : adj[i]) {
                if (leafs[neighbour]) 
                    leafCount++;
            }
            isSpruce &= (leafCount >= 3);
        }
    }

    if (isSpruce) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> parentIndex(n - 1);
    for (int i = 0; i < n - 1; i++) 
        cin >> parentIndex[i];

    solve(n, parentIndex);

    return 0;
}