// #include<iostream>
// #include<vector>
// using namespace std;
// //this function is to add the edge of the vertices
// void addEdge(vector<vector<int>>& adj,int u,int v){
//     adj[u].push_back(v);//adding v to the adjacency list of u
//     adj[v].push_back(u);//adding u to the adjacency list of v

// }
// void greedyColouring(vector<vector<int>>& adj,int V){
    
//     //initialize the vector of vertices and initially assign
//     //-1 and eventuallu store all the colours
//     vector<int> result(V,-1);
//     result[0] = 0;

//     //a vector to track avaliable colours with maximum capacity
//     //of the number of vertices and initially assign all of them
//     //to false
//     vector<bool> avaliable(V,false);

//     for(int u = 1; u < V; u++){
//         for(int i : adj[u]){
//             if(result[i] != -1){
//                 avaliable[result[i]] = true;//discard the neighbour colour 
//                                             //and make it unavaliable
//             }
//         }
    
//     int color;
//     for(int color = 0; color< V; color++){
//         if(!avaliable[color]){
//             break;//this means that if we we have found the avaliable
//                     //color then we should break out of the loop
//         }
        
//     }

//     result[u] = color;//assign the found
//     for(int i : adj[u]){
//         if(result[i] != -1){//if the neighbour is coloured
//             avaliable[result[i]] == false;
//         }
//     }
//     }
//     for(int u = 0 ; u < V; u++){
//         cout<<"Vertex "<< u << "---> Colour "<< result[u]<<endl;
//     }
// }
// int main(){
//     int V,E;
//     cout<<"Enter the number of vertices: ";
//     cin>>V;

//     //created an adjacency list to store the edges are 
//     //the combination of 2 vertices
//     vector<vector<int>> adj(V);

//     cout<<"Enter the number of edges";
//     cin>>E;

//     //here we are getting the actual edges so we are taking 
//     //u ie the starting vertex and v the ending vertex of the 
//     //edge.
//     cout<<"Enter the edges(u v)";
//     for(int i = 0; i < E; i++){
//         int u , v;
//         cin>>u>>v;
//         addEdge(adj , u ,v);
//     }

//     greedyColouring(adj,V);

//     return 0;
// }

#include<iostream>
#include<vector>
using namespace std;

// This function is to add the edge of the vertices
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v); // Adding v to the adjacency list of u
    adj[v].push_back(u); // Adding u to the adjacency list of v
}

void greedyColouring(vector<vector<int>>& adj, int V) {
    // Initialize the vector of vertices and initially assign -1
    vector<int> result(V, -1);
    result[0] = 0; // Assign the first color to the first vertex

    // A vector to track available colors with maximum capacity
    vector<bool> avaliable(V, false);

    // Assign colors to remaining vertices
    for (int u = 1; u < V; u++) {
        // Reset available colors for each vertex
        fill(avaliable.begin(), avaliable.end(), false);

        // Mark colors of adjacent vertices as unavailable
        for (int i : adj[u]) {
            if (result[i] != -1) {
                avaliable[result[i]] = true; // Discard the neighbor color and make it unavailable
            }
        }

        // Find the first available color
        int color;
        for (color = 0; color < V; color++) {
            if (!avaliable[color]) {
                break; // If we have found the available color, break out of the loop
            }
        }

        result[u] = color; // Assign the found color
    }

    // Output the color of each vertex
    for (int u = 0; u < V; u++) {
        cout << "Vertex " << u << " ---> Colour " << result[u] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    // Create an adjacency list to store the edges as combinations of 2 vertices
    vector<vector<int>> adj(V);

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges (u v): ";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    greedyColouring(adj, V);

    return 0;
}
