//Given a graph find the minimum spanning tree (Prim's Algorithm).
/*
Algorithm :
    1. We 3 arrays in this case.
    2. One array for keeping track of distance, One for parent and One for MST(Visited).
    3. Make source nodes distance as zero and parent as -1 and MST as true in the begining.
    4. Find the minimum in distance array and pick that respective node.
    5. Update the distance and parent array only if weight value of adjacent nodes is less than current position value and that node is marked as false in MST array.
    6. Final parent array is the answer.
    7. Time Complexity : O(n^2), Space Complexity : O(V).
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<limits.h>
#include<algorithm>
using namespace std;



int main()
{
    int vertices, edges;
    cout<<"Enter the number of vertices"<<endl;
    cin>>vertices;

    cout<<"Enter the number of edges"<<endl;
    cin>>edges;

    //Create the Adjacency List.
    unordered_map<int,vector<pair<int,int>>> adjList;
    cout<<"Enter the input in the format node1, node2 and respective weight"<<endl;
    for(int i=0; i<edges; i++){
        int u, v, weight;
        cin>>u>>v>>weight;

        adjList[u].push_back({v,weight});
        adjList[v].push_back({u,weight});
    }

    //Prim's Algorithm.
    vector<int> key(vertices,INT_MAX);
    vector<int> parent(vertices,-1);
    vector<bool> MST(vertices,false);

    int source;
    cout<<"Enter the source node"<<endl;
    cin>>source;
    
    //Initial assignment.
    key[source] = 0;
    parent[source] = -1;
    MST[source] = true;

    for(int i=0; i<vertices; i++){
       //int mini = *min_element(key.begin(),key.end());
        int mini = INT_MAX;
        int u;

        for(int v=0; v<vertices; v++){
            if(MST[v] == false && key[v] < mini){
                u = v;
                mini = key[v];
            }
        }

        //Mark min node as true.
        MST[u] = true;

        //Check its Adjacency List.
        for(auto neighbour : adjList[u]){
            int node = neighbour.first;
            int weight = neighbour.second;

            if(MST[node] == false && key[node] > weight){
                parent[node] = u;
                key[node] = weight;
            }
        }
    }

    //Printing answer.
    cout<<"Minimum spanning tree is given by"<<endl;
    for(int i=0; i<vertices; i++){
        cout<<i<<"-->"<<parent[i]<<" = "<<key[i]<<endl;
    }
    cout<<endl;

    return 0;
}