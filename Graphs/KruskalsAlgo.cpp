#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int source;
    int dest;
    int wt;
};

bool cmp(Edge e1, Edge e2) {
    return e1.wt < e2.wt;
}

int main() {
    int n, e;
    cin >> n >> e;
    Edge input[e];
    for(int i = 0; i < e; ++i) {
        cin >> input[i].source >> input[i].dest >> input[i].wt;
    }
    sort(input, input + e, cmp);
    Edge output[n - 1];
    int parent[n];
    for(int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    int count = 0;
    for(int i = 0; i < e; i++) {
        int v1 = input[i].source;
        int v2 = input[i].dest;
        int p1 = input[i].source;
        int p2 = input[i].dest;
        while(parent[p1] != p1) {
            p1 = parent[p1];
        }
        while(parent[p2] != p2) {
            p2 = parent[p2];
        }
        if(p1 != p2) {
            output[count].source = v1;
            output[count].dest = v2;
            output[count].wt = input[i].wt;
            parent[p2] = parent[p1];
            count++;
        }
        if(count == n - 1) break;
    }
    cout << "Here is the output" << endl;
    for(auto &c : output) {
        cout << c.source << " " << c.dest << " " << c.wt << endl;
    }
    return 0;
}