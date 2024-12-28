#include <iostream>
#include <vector>
using namespace std;

// Function to add an undirected edge between two vertices
void addEdge(vector<vector<int>>& adj, int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

// Greedy coloring function
void greedyColoring(const vector<vector<int>>& adj, int V) {
    vector<int> result(V, -1); // Color assignments for vertices
    result[0] = 0; // Assign the first color to the first vertex

    vector<bool> available(V, false); // Track available colors

    // Assign colors to remaining vertices
    for (int u = 1; u < V; u++) {
        // Mark colors of adjacent vertices as unavailable
        for (int i : adj[u]) {
            if (result[i] != -1) {
                available[result[i]] = true;
            }
        }

        // Find the first available color
        int color;
        for (color = 0; color < V; color++) {
            if (!available[color]) {
                break;
            }
        }

        result[u] = color; // Assign the found color

        // Reset the available array for the next vertex
        for (int i : adj[u]) {
            if (result[i] != -1) {
                available[result[i]] = false;
            }
        }
    }

    // Output the color of each vertex
    for (int u = 0; u < V; u++) {
        cout << "Vertex " << u << " ---> Color " << result[u] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    // Create an adjacency list for the graph
    vector<vector<int>> adj(V);

    //take number of edges as an input
    cout << "Enter the number of edges: ";
    cin >> E;

    //loop from i = 0 to E -1 to keep on adding the 
    //edges in the adj list.
    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    greedyColoring(adj, V);

    return 0;
}
