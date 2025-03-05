#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>>& edges) {
    for(auto i : edges) { 
        for(auto &j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
void minCostConnectPoints(vector<vector<int>> &points)
{
    int n = points.size();
    vector<vector<int>> edges;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
                continue;
            int manhattanDist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            edges.push_back({i, j, manhattanDist});
        }
    }
    print(edges);
}
int main() {
    int n; 
    cin >> n;
    vector<vector<int>> points(n);
    for(int i = 0; i < n; ++i) {
        int fv, sv;
        cin >> fv >> sv;
        points[i] = {fv, sv};
    }
    minCostConnectPoints(points);
    return 0;
}