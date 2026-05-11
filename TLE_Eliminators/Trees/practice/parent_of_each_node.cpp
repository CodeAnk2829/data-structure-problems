#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(vector<vector<int>>& arr, int node, int parent, vector<int>& parents) {
    parents[node] = parent;
    for(int child : arr[node]) {
        if(child != parent) {
            dfs(arr, child, node, parents);
        }
    }
}

void bfs(vector<vector<int>>& arr, int root, vector<int>& parents) {
    vector<int> visited(arr.size() + 1);
    queue<int> q;
    q.push(root);
    visited[root] = 1;
    parents[root] = -1;
    while(!q.empty()) {
        int currNode = q.front();
        q.pop();
        for(auto child : arr[currNode]) {
            if(!visited[child]) {
                q.push(child);
                visited[child] = 1;
                parents[child] = currNode;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n + 1);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    // for(int i = 1; i <= n; i++) {
    //     cout << i << ": ";
    //     for(auto &child : arr[i]) {
    //         cout << child << ", ";
    //     }
    //     cout << endl;
    // }
    vector<int> parents(n + 1);
    // dfs(arr, 0, -1, parents);
    bfs(arr, 1, parents);
    for(int i = 1; i <= n; i++) {
        cout << i << " : " << parents[i] << endl;
    }
    return 0;
}