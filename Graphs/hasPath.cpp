#include <bits/stdc++.h>
using namespace std;
bool helperHasPath(int** edges, int n, int sv, int ev, bool* visited) {
    if(edges[sv][ev] == 1) {
        return true;
    }
    visited[sv] = true;
    bool flag = false;
    for(int i = 0; i < n; ++i) {
        if(i == sv) {
            continue;
        }
        if(edges[sv][i] == 1 && !visited[i]) {
            flag = flag || helperHasPath(edges, n, i, ev, visited);
        }
    }
    return flag;
}
bool hasPath(int** edges, int n, int sv, int ev) {
    bool* visited = new bool[n];
    for(int i = 0; i < n; ++i) {
        visited[i] = false;
    }
    bool result = helperHasPath(edges, n, sv, ev, visited);
    delete [] visited;
    return result;
}
 
int main() {
    int n, e;
    cin >> n >> e;
    int** edges = new int*[n];
    for(int i = 0; i < n; ++i) {
        edges[i] = new int[n];
        for(int j = 0; j < n; ++j) {
            edges[i][j] = 0;
        }
    }
    for(int i = 0; i < e; ++i) {
        int fv, sv;
        cin >> fv >> sv;
        edges[fv][sv] = 1;
        edges[sv][fv] = 1;
    }

    int sv, ev;
    cin >> sv >> ev;
    cout << hasPath(edges, n, sv, ev);

    // Delete
    for(int i = 0; i < n; ++i) {
        delete [] edges[i];
    }
    delete [] edges;
    
    return 0;
}