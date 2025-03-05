#include <bits/stdc++.h>
using namespace std;
void findPath(vector<vector<int>>& edges, int source, int dest) {
    int n = edges.size(); // no. of vertices
    vector<bool> used(n);
    vector<int> length(n), parent(n);

    queue<int> q;

    q.push(source);
    used[source] = true;
    parent[source] = -1;

    // find shortest path from source vertex to each vertex
    // also find length
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(auto u : edges[v]) {
            if(!used[u]) {
                used[u] = true;
                q.push(u);
                length[u] = length[v] + 1;
                parent[u] = v;
            }
        }
    }

    // print parent array
    cout << "Parents: " << endl;
    for(auto p : parent) {
        cout << p << " ";
    }
    cout << endl;
    
    //print distance array
    cout << "Distances: " << endl;
    for(auto d : length) {
        cout << d << " ";
    }
    cout << endl;

    // find path from source to destination
    if(!used[dest]) {
        cout << "No path!" << endl;
    } else {
        vector<int> path;
        for(int v = dest; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        cout << "Path: ";
        for(auto &v : path) {
            cout << v << " ";
        }
        cout << endl;
    }

    // shortest distance between source and destination
    cout << "Distance : " << length[dest] << endl;
}


int main() {
    int n;
    cin >> n;

    vector<vector<int>> edges(n);
    for(int i = 0; i < n; ++i) {
        int adj;
        cin >> adj;
        for(int j = 0; j < adj; ++j) {
            int x;
            cin >> x;
            edges[i].push_back(x);
        }
    }
    int source, destination;
    cin >> source >> destination;

    findPath(edges, source, destination);
    
    return 0;
}