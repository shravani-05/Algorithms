#include <iostream>
#include <vector>
#include <climits>
#include <stack>

using namespace std;

// Number of vertices in the graph
#define V 6

// Depth-First Search function to find if there is a path from source to sink in residualGraph
bool dfs(vector<vector<int>>& residualGraph, int source, int sink, vector<int>& parent) {
    vector<bool> visited(V, false); // Keeps track of visited nodes
    stack<int> s;
    s.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!s.empty()) {
        int u = s.top();
        s.pop();

        // Traverse all nodes connected to u
        for (int v = 0; v < V; v++) {
            // If node v is not visited and there is available capacity from u to v
            if (!visited[v] && residualGraph[u][v] > 0) {
                s.push(v);
                parent[v] = u;
                visited[v] = true;
                // If we reached the sink, path exists
                if (v == sink) {
                    return true;
                }
            }
        }
    }
    return false; // No path found
}

// Ford-Fulkerson Algorithm to find maximum flow from source to sink
int fordFulkerson(vector<vector<int>>& graph, int source, int sink) {
    vector<vector<int>> residualGraph = graph; // Initialize residual graph with initial capacities
    vector<int> parent(V); // Stores the path

    int maxFlow = 0; // Initialize maximum flow

    // Augment flow while there is a path from source to sink
    while (dfs(residualGraph, source, sink, parent)) {
        // Find the maximum flow through the path found by DFS
        int bottleneck = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            bottleneck = min(bottleneck, residualGraph[u][v]);
        }

        // Update residual capacities of edges and reverse edges along the path
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= bottleneck;
            residualGraph[v][u] += bottleneck;
        }

        // Add path flow to the overall flow
        maxFlow += bottleneck;
    }

    return maxFlow;
}

int main() {
    // Define a graph where graph[u][v] indicates capacity of edge from u to v
    vector<vector<int>> graph = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    int source = 0, sink = 5;
    cout << "The maximum possible flow is " << fordFulkerson(graph, source, sink) << endl;

    return 0;
}
