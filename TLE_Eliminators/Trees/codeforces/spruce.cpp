#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> parent(n + 1), deg(n + 1);
    for(int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        parent[i] = p;
        deg[p]++;
    }

    map<int, vector<int>> edges;
    for(int i = 2; i <= n; i++) {
        if(deg[i] == 0) {
            edges[parent[i]].push_back(i);
        }
    }

    bool ans = true;
    for(int i = 1; i <= n; i++) {
        if(deg[i] && edges[i].size() < 3) {
            ans = false;
            break;
        }
    }

    if(ans) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}