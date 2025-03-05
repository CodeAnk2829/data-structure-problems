// problem link: https://www.spoj.com/problems/CLFLARR/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
private:
    vector<int> parent, size;

public: 

    DisjointSet(int n) {
        for(int i = 0; i <= n + 1; ++i) {
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
        parent[pu] = pv;
    }
};



vector<int> finalColor(int n, int q, vector<vector<int>>& arr) {
    reverse(arr.begin(), arr.end());

    DisjointSet d(n);
    vector<int> result(n + 1);
    
    for(auto &it : arr) {
        int leftNode = it[0];
        int rightNode = it[1];
        int color = it[2];

        for(int i = leftNode; i <= rightNode; ++i) {
            int ultParent = d.findParent(i);
            if(ultParent == i) {
                result[i] = color;
                d.unionSize(i, i + 1);
            } else {
                i = ultParent - 1;
            }
        }
    }

    return result;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> queries(q);
    for(int i = 0; i < q; ++i) {
        int left, right, color;
        cin >> left >> right >> color;
        queries[i] = {left, right, color};
    }

    vector<int> result = finalColor(n, q, queries);
    for(int i = 1; i <= n; ++i) {
        cout << result[i] << endl;
    }
    return 0;
}