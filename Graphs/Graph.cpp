#include <bits/stdc++.h>
using namespace std;

// Depth First Traversal
void printDFS(int** edges, int n, int sv, bool* visited) {
    // printDFS the starting vertex
    cout << sv << " ";

    // Mark the starting vertex as visited
    visited[sv] = true;

    // Loop to check the possible connections between sv and n vertices
    for(int i = 0; i < n; ++i) {
        if(i == sv) {
            continue;
        }
        if(edges[sv][i] == 1) {
            if(visited[i]) {
                continue;
            }
            printDFS(edges, n, i, visited);
        }
    }
}

// Breadth First Traversal
void printBFS(int** edges, int n, int sv, bool* visited) {
    queue<int> unvisitedVertices;
    unvisitedVertices.push(sv);
    visited[sv] = true;

    while(!unvisitedVertices.empty()) {
        int currentVertex = unvisitedVertices.front();
        unvisitedVertices.pop();
        cout << currentVertex << " ";
        for(int i = 0; i < n; ++i) {
            if(i == currentVertex) {
                continue;
            }
            if(edges[currentVertex][i] == 1 && !visited[i]) {
                unvisitedVertices.push(i);
                visited[i] = true;
            } 
        }
    }
    cout << endl;
}

void DFS(int** edges, int n) {
    // Bool array to maintain a record of visited vertices
    bool *visited = new bool[n];
    for (int i = 0; i < n; ++i) {
        visited[i] = false;
    }
    for(int i = 0; i < n; ++i) {
        if(!visited[i]) {
            printDFS(edges, n, i, visited);
            cout << endl;
        }
    }
    delete [] visited;
}

void BFS(int** edges, int n) {
    // Bool array to maintain a record of visited vertices
    bool *visited = new bool[n];
    for (int i = 0; i < n; ++i) {
        visited[i] = false;
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            printBFS(edges, n, i, visited);
        }
    }
    delete[] visited;
}

int main() {

    // Take input no. of vertices and no. of edges
    int n;
    int e;
    cin >> n >> e;

    // Declare a 2D array to store the record of edges
    int** edges = new int*[n];

    // Fill the edges 2D array with 0 initially indicating that no connections yet
    for(int i = 0; i < n; ++i) {
        edges[i] = new int[n];
        for(int j = 0; j < n; ++j) {
            edges[i][j] = 0;
        }
    }

    // Marking connections between first vertex and second vertex
    for(int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    

    // printDFS
    cout << "DFS" << endl;
    DFS(edges, n);
    cout << endl;

    cout << "BFS" << endl;
    BFS(edges, n);

    // Delete
    for(int i = 0; i < n; ++i) {
        delete [] edges[i];
    }
    delete [] edges;
    return 0;
}