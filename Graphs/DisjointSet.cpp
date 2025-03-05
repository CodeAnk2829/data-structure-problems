#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
private:
    vector<int> parent, rank, size;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int findUltParent(int node) {
        if(parent[node] == node){
            return node;
        }

        return parent[node] = findUltParent(parent[node]);
    }

    void unionByRank(int node1, int node2) {
        int ultParent1 = findUltParent(node1);
        int ultParent2 = findUltParent(node2);

        if(ultParent1 == ultParent2) {
            return;
        }

        if(rank[ultParent1] > rank[ultParent2]) {
            parent[ultParent2] = ultParent1;
        } else if(rank[ultParent2] > rank[ultParent1]) {
            parent[ultParent1] = ultParent2;
        } else {
            parent[ultParent2] = ultParent1;
            rank[ultParent1]++;
        }
    }

    void unionBySize(int node1, int node2) {
        int ultParent1 = findUltParent(node1);
        int ultParent2 = findUltParent(node2);

        if(ultParent1 == ultParent2) return;

        if(size[ultParent1] > size[ultParent2]) {
            parent[ultParent2] = ultParent1;
            size[ultParent1] += size[ultParent2];
        } else {
            parent[ultParent1] = ultParent2;
            size[ultParent2] += size[ultParent1];
        }
    }
};

int main() {
    DisjointSet dsu(6);
    dsu.unionBySize(1, 2);
    dsu.unionBySize(2, 3);
    dsu.unionBySize(3, 4);

    if(dsu.findUltParent(4) == dsu.findUltParent(5)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    dsu.unionBySize(4, 5);

    if (dsu.findUltParent(4) == dsu.findUltParent(5)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    dsu.unionBySize(5, 3);
    dsu.unionBySize(3, 1);

    return 0;
}