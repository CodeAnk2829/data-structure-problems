#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& arr, int root, int parent, vector<int>& in, vector<int>& out, int& count) {
    in[root] = ++count;
    for(int child : arr[root]) {
        if(child != parent) {
            dfs(arr, child, root, in, out, count);
        }
    }
    out[root] = ++count;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    vector<int> in(n), out(n);
    int count = 0;
    dfs(arr, 0, -1, in, out, count);
    for(int i : in) cout << i << " ";
    cout << endl;
    for(int o : out) cout << o << " ";
    cout << endl;
    return 0;
}