#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(vector<vector<int>>& arr, int root, int parent, vector<int>& s) {
    s[root] = 1;
    for(int child : arr[root]) {
        if(child != parent) {
            dfs(arr, child, root, s);
            s[root] += s[child];
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

    vector<int> subtreeSizeOfEachNode(n + 1);
    dfs(arr, 1, -1, subtreeSizeOfEachNode);
    for(int i = 1; i <= n; i++) {
        cout << i << " : " << subtreeSizeOfEachNode[i] << endl;
    }
    return 0;
}