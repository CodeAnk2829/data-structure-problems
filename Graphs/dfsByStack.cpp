#include <bits/stdc++.h>
using namespace std;

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    stack<int> s;
    vector<int> dfs, visited(V, 0);

    s.push(0);

    while (!s.empty())
    {
        int top = s.top();
        s.pop();

        if (!visited[top])
        {
            visited[top] = 1;
            dfs.push_back(top);

            for (auto it = adj[top].rbegin(); it != adj[top].rend(); it++)
            {
                s.push(*it);
            }
        }
    }
    return dfs;
}