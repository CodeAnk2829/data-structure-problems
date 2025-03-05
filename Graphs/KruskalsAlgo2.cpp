#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    int findUltParent(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findUltParent(parent[node]);
    }

    bool unionBySize(int u, int v)
    {
        int ultParent1 = findUltParent(u);
        int ultParent2 = findUltParent(v);

        if (ultParent1 == ultParent2)
            return false;

        if (size[ultParent1] > size[ultParent2])
        {
            parent[ultParent2] = ultParent1;
            size[ultParent1] += size[ultParent2];
        }
        else
        {
            parent[ultParent1] = ultParent2;
            size[ultParent2] += size[ultParent1];
        }
        return true;
    }
};

void printMST(vector<vector<int>> &edges, int v, int e)
{
    multimap<int, pair<int, int>> m;
    for (auto &e : edges)
    {
        m.insert({e[2], {e[0], e[1]}});
    }

    DisjointSet dsu(e);

    for (auto &it : m)
    {
        int fv = min(it.second.first, it.second.second);
        int sv = max(it.second.first, it.second.second);
        int wt = it.first;
        if (dsu.unionBySize(fv, sv))
        {
            cout << fv << " " << sv << " " << wt << endl;
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> edges(e, vector<int>(3));
    for (int i = 0; i < e; ++i)
    {
        int fv, sv, wt;
        cin >> fv >> sv >> wt;
        vector<int> temp = {fv, sv, wt};
        edges[i] = temp;
    }

    printMST(edges, v, e);
    return 0;
}