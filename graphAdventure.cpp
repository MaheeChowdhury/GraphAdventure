#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;

    // Initialize adjacency matrix
    vector<vector<int>> adj(v, vector<int>(v, 0));

    cout << "Enter edges (u v) starting from 0:\n";
    for (int i = 0; i < e; i++) {
        int u, w;
        cin >> u >> w;
        adj[u][w] = 1;
        adj[w][u] = 1; // undirected graph
    }

    // 1. Print Adjacency Matrix
    cout << "\n--- Adjacency Matrix ---\n  ";
    for (int i = 0; i < v; i++) cout << i << " ";
    cout << endl;
    for (int i = 0; i < v; i++) {
        cout << i << " ";
        for (int j = 0; j < v; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }

    // 2. Degree of each vertex
    cout << "\n--- Degree of Each Vertex ---\n";
    int maxDeg = 0, maxVertex = 0;
    for (int i = 0; i < v; i++) {
        int degree = 0;
        for (int j = 0; j < v; j++)
            degree += adj[i][j];
        cout << "Vertex " << i << " : Degree = " << degree << endl;
        if (degree > maxDeg) {
            maxDeg = degree;
            maxVertex = i;
        }
    }
    cout << "Most connected vertex: " << maxVertex
         << " with degree " << maxDeg << endl;

    // 3. Check Connectivity using BFS
    cout << "\n--- Connectivity Check ---\n";
    vector<bool> visited(v, false);
    queue<int> bfsQueue;
    bfsQueue.push(0);
    visited[0] = true;
    int visitedCount = 1;

    while (!bfsQueue.empty()) {
        int node = bfsQueue.front();
        bfsQueue.pop();
        for (int j = 0; j < v; j++) {
            if (adj[node][j] == 1 && !visited[j]) {
                visited[j] = true;
                visitedCount++;
                bfsQueue.push(j);
            }
        }
    }

    if (visitedCount == v)
        cout << "Graph is CONNECTED ✓\n";
    else
        cout << "Graph is NOT connected ✗\n";

    // 4. Count total edges
    int totalEdges = 0;
    for (int i = 0; i < v; i++)
        for (int j = i + 1; j < v; j++)
            if (adj[i][j] == 1) totalEdges++;

    cout << "\n--- Total Edges ---\n";
    cout << "Total number of edges: " << totalEdges << endl;

    return 0;
}