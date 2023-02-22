#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool detectCycleDFS(int node, int parent, unordered_map<int,bool> &visited, unordered_map<int,vector<int>> &adjList){
    visited[node] = true;

    for(auto neighbour : adjList[node]){
        if(!visited[neighbour]){
            bool cycleDetected = detectCycleDFS(neighbour, node, visited, adjList);
            if(cycleDetected == true){
                return true;
            }
        }
        else if(neighbour != parent){
            return true;
        }
    }
    return false;
}

int main()
{
    unordered_map<int,vector<int>> adjList;

    int vertices, edges;
    cout<<"Enter the number of vertices"<<endl;
    cin>>vertices;

    cout<<"Enter the number of edges"<<endl;
    cin>>edges;

    //Creating adjacecy List of undirected graph.
    for(int i=0; i<edges; i++){
        int u,v;
        cin>>u>>v;
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    //For disconnected component.
    unordered_map<int,bool> visited;
    for(int i=0; i<vertices; i++){
        if(!visited[i]){
            bool ans = detectCycleDFS(i, -1, visited, adjList);
            if(ans == true){
                cout<<"Cycle is present in the graph"<<endl;
                return 0;
            }
        }
    }

    cout<<"Cycle is not present in the graph"<<endl;

    return 0;
}