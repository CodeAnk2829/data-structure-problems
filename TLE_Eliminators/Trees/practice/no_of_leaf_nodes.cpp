#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int>>& arr, int root, int parent) {
    if(arr[root].size() <= 1 && arr[root][0] == parent) return 1;
    int noOfLeafNodes = 0;
    for(int child : arr[root]) {
        if(child != parent) {
            noOfLeafNodes += dfs(arr, child, root);
        }
    }

    return noOfLeafNodes;
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

    int ans = dfs(arr, 1, -1);
    cout << ans << endl;
    return 0;
}