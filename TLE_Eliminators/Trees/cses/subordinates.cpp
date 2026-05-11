#include <iostream>
#include <vector>

using namespace std;

void solve(vector<vector<int>>& tree, int root, int parent, vector<int>& sub) {
    for(int child : tree[root]) {
        if(child != parent) {
            solve(tree, child, root, sub);
            sub[root] += sub[child];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    cin >> n;
    vector<vector<int>> tree(n + 1);
    for(int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        tree[i].push_back(x);
        tree[x].push_back(i);
    }

    vector<int> subordinates(n + 1, 1);
    solve(tree, 1, -1, subordinates);

    for(int i = 1; i <= n; i++) {
        cout << subordinates[i] - 1 << " ";
    }
    
    return 0;
}
