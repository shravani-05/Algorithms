#include <stdio.h>
#include <string.h>
#include <limits.h>

#define V 6  // Number of vertices in the graph

// Function to find the maximum flow using Push-Relabel algorithm
int pushRelabel(int graph[V][V], int s, int t) {
    int excess[V] = {0}, height[V] = {0}, flow[V][V] = {0};
    height[s] = V;
    for (int i = 0; i < V; i++) {
        if (graph[s][i] > 0) {
            flow[s][i] = graph[s][i];
            flow[i][s] = -graph[s][i];
            
            excess[i] = graph[s][i];
            excess[s] -= graph[s][i];
        }
    }

    while (1) {
        int u = -1;
        for (int i = 0; i < V; i++)
            if (i != s && i != t && excess[i] > 0) {
                u = i;
                break;
            }
        if (u == -1) break;

        int minHeight = INT_MAX;
        for (int v = 0; v < V; v++) {
            if (graph[u][v] - flow[u][v] > 0 && height[u] > height[v]) {
                int pushFlow = (excess[u] < (graph[u][v] - flow[u][v])) ? excess[u] : (graph[u][v] - flow[u][v]);
                flow[u][v] += pushFlow;
                flow[v][u] -= pushFlow;
                excess[u] -= pushFlow;
                excess[v] += pushFlow;
            } else if (graph[u][v] - flow[u][v] > 0)
                minHeight = (minHeight < height[v]) ? minHeight : height[v];
        }

        if (excess[u] > 0)
            height[u] = minHeight + 1;
    }

    int maxFlow = 0;
    for (int i = 0; i < V; i++)
        maxFlow += flow[s][i];
    return maxFlow;
}

int main() {
    int graph[V][V] = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };
    printf("The maximum flow is %d\n", pushRelabel(graph, 0, 5));
    return 0;
}