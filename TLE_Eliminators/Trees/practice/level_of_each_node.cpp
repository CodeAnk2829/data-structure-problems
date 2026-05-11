#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(vector<vector<int>>& arr, int root, int parent, int currLevel, vector<int>& level) {
    level[root] = currLevel;
    for(auto& child : arr[root]) {
        if(child != parent) {
            dfs(arr, child, root, currLevel + 1, level);
        }
    }
}

void bfs(vector<vector<int>> arr, int root, vector<int>& level) {
    vector<int> visited(arr.size());
    queue<pair<int, int>> pendingNodes;
    pendingNodes.push({root, 0});
    visited[root] = 1;

    while(!pendingNodes.empty()) {
        pair<int, int> front = pendingNodes.front();
        int node = front.first;
        int currLevel = front.second;
        pendingNodes.pop();
        level[node] = currLevel;
        
        for(auto child : arr[node]) {
            if(!visited[child]) {
                pendingNodes.push({child, currLevel + 1});
                visited[child] = 1;
            }
        }
    }
}

int main() {    
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    vector<int> level(n, 0);
    // dfs(arr, 0, -1, 0, level);
    bfs(arr, 0, level);
    for(int i = 0; i < n; i++) {
        cout << i << ": " << level[i] << endl;
    }
    return 0;
}