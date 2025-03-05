#include <bits/stdc++.h>
using namespace std;

int minCostPath(int** edges, int n, int s, int d, int* cost) {
    // Base Case
    if(s == d) {
        cost[s] = 0;
        return 0;
    }

    // if the ans is already calculated then return the strored value
    if(cost[s] != -1) {
        return cost[s];
    }

    // Calculating the minimum cost
    int m = INT_MAX;
    for(int i = 1; i <= n; ++i) {
        if(i == s) {
            continue;
        }
        if(edges[s][i] != 0) {
            int tempAns = edges[s][i] + minCostPath(edges, n, i, d, cost);
            m = min(m, tempAns);
        }
    }

    // Store the ans in its corresponding vertex
    cost[s] = m;
    return m;
}

int multiStageGraph(int** edges, int n, int s, int d) {
    int* cost = new int[n + 1];
    for(int i = 0; i <= n; ++i) {
        cost[i] = -1;
    }
    int ans = minCostPath(edges, n, s, d, cost);
    delete [] cost;
    return ans;
}

int main() {
    // Number of vertices and Number of edges
    int n, e;
    cin >> n >> e;

    // Input in edges adjacency matrix
    int** edges = new int*[n + 1];

    for(int i = 0; i <= n; ++i) {
        edges[i] = new int[n + 1];
        for(int j = 0; j <= n; ++j) {
            edges[i][j] = 0;
        }
    }

    for(int i = 0; i < e; ++i) {
        int source;
        int dest;
        int cost;
        cin >> source >> dest >> cost;
        edges[source][dest] = cost;
    }

    // Find ans
    int ans = multiStageGraph(edges, n, 1, 10);
    cout << ans << endl;

    // Delete 
    for(int i = 0; i <= n; ++i) {
        delete [] edges[i];
    }
    delete [] edges;

    return 0;
}