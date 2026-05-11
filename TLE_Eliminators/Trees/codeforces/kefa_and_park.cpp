#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& tree, vector<int>& c, int m, int root, int parent, int sumOfConsecutiveNodesWithCat) {
    if(c[root] == 1) {
        sumOfConsecutiveNodesWithCat++;
    } else {
        sumOfConsecutiveNodesWithCat = 0;
    }

    if(sumOfConsecutiveNodesWithCat > m) return 0;

    int noOfChildren = 0;
    int noOfRestaurants = 0;
    for(int child : tree[root]) {
        if(child != parent) {
            noOfChildren++;
            noOfRestaurants += dfs(tree, c, m, child, root, sumOfConsecutiveNodesWithCat);
        }
    }

    if(noOfChildren == 0) return 1;
    return noOfRestaurants;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> catPositions(n + 1);
    for(int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        catPositions[i] = c;
    }

    vector<vector<int>> tree(n + 1);
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    int ans = dfs(tree, catPositions, m, 1, -1, 0);
    cout << ans << endl;

    return 0;
}