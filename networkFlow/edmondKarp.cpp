#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

#define V 6

bool bfs(vector<vector<int>> &residual, int source, int sink,vector<int> &parentpath){
    vector<bool> visited(V,false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    parentpath[source] =-1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v = 0; v < V; v++){
            if(!visited[v] && residual[u][v] > 0){
                q.push(v);
                parentpath[v] = u;
                visited[v] = true;


                if(v == sink){
                    return true;
                }
            }
        }
    }
    return false;
}
int edmondKarp(vector<vector<int>> &graph,int source,int sink){
    vector<vector<int>> residual = graph; //declare a residual graph with initally same values as graph
    vector<int> parentpath(V);

    int maxflow = 0;

    while(bfs(residual , source,sink,parentpath)){
        int bottleneck = INT_MAX;

        for(int v = sink; v != source; v = parentpath[v]){//start from the sink and traverse till source
            int u = parentpath[v];//parentpath is stored as u
            bottleneck = min(bottleneck, residual[u][v]);//minimum among all the edges is determined to find the residual
        }

        for(int v = sink; v!= source; v = parentpath[v]){
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
    cout<<"Maximum network flow: "<<edmondKarp(graph,source,sink);
    return 0;
}