#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> find(int n, vector<vector<int>>& ankit) {
    int e = ankit.size();
    vector<vector<int>> edges;
    for(int i = 0; i < e; ++i) {
        vector<int> v;
        v.push_back(ankit[i][2]);
        v.push_back(ankit[i][0]);
        v.push_back(ankit[i][1]);
        edges.push_back(v);
    }
    sort(edges.begin(), edges.end());
    // for(auto &p: edges) {
    //     cout << p[0] << " " << p[1] << " " << p[2] << endl;
    // }
    vector<int> parent;
    for(int i = 0; i < n; ++i) {
        parent.push_back(i);
    }
    int count = 0;
    vector<vector<int>> output;
    for(int i = 0; i < e; ++i) {
        int v1 = edges[i][1];
        int v2 = edges[i][2];
        int p1 = v1;
        int p2 = v2;
        while(parent[p1] != p1) {
            p1 = parent[p1];
        }
        while(parent[p2] != p2 ) {
            p2 = parent[p2];
        }
        if(p1 != p2) {
            vector<int> temp;
            temp.push_back(v1);
            temp.push_back(v2);
            output.push_back(temp);
            parent[p1] = parent[p2];
            count++;
        }
        if(count == n - 1) break;
    }
    return output;
}
int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges;
    for(int i = 0; i < e; ++i) {
        vector<int> v;
        int sv, ev, wt;
        cin >> sv >> ev >> wt;
        v.push_back(sv);
        v.push_back(ev);
        v.push_back(wt);
        edges.push_back(v);
    }
    vector<vector<int>> f = find(n, edges);
    for(auto &p : f) {
        cout << p[0] << " " << p[1] << endl;
    }
    return 0;
}