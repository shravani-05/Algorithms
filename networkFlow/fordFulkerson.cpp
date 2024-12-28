#include<bits/stdc++.h>
using namespace std;
#define V 6
int dfs(vector<vector<int>> &residual, int source, int sink, vector<int> &parentpath){
    vector<bool> visited(V,false);
    stack<int> s;
    s.push(source);
    parentpath[source] = -1;

    while(!s.empty()){
        int u = s.top();
        s.pop();

        for(int v = 0; v < V; v++){
            if(!visited[v] && residual[u][v] > 0){
            s.push(v);
            parentpath[v] = u;
            visited[v] =true;
                if(v == sink){
                    return true;
                }
            }
        }  
    }
    return false;
}
int fordFulkerson(vector<vector<int>> &graph,int source,int sink){
    vector<vector<int>> residual = graph; //at the start residual and graph are the same thing
    vector<int> parentpath(V);//stores the path from the source to the sink
    int maxflow = 0;

    while(dfs(residual,source,sink,parentpath)){
        int bottleneck = INT_MAX;

        for(int v = sink; v != source; v=parentpath[v]){
            int u = parentpath[v];
            bottleneck = min(bottleneck, residual[u][v]);
        }

        for(int v = sink; v != source; v = parentpath[v]){
            int u = parentpath[v];

            residual[u][v] -= bottleneck;
            residual[v][u] += bottleneck;
        }
        maxflow += bottleneck;
    }
    return maxflow;
}
int main(){
    vector<vector<int>> graph = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    int source = 0, sink = 5;
    cout<<"Maximum flow = "<<fordFulkerson(graph,source,sink);
    return 0;
}