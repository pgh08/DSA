#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

bool detectCycleDFS(int node, unordered_map<int,bool> &visited, unordered_map<int,bool> &dfsVisisted, unordered_map<int,vector<int>> &adjList){
    visited[node] = true;
    dfsVisisted[node] = true;

    for(auto neighbour : adjList[node]){
        if(!visited[neighbour]){
            bool ans = detectCycleDFS(neighbour, visited, dfsVisisted, adjList);
            if(ans == true){
                return true;
            }
        }
        else if(dfsVisisted[neighbour]){
            return true;
        }
    }
    dfsVisisted[node] = false;

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

    //Creating Adjacency List.
    for(int i=0; i<edges; i++){
        int u,v;
        cin>>u>>v;

        adjList[u].push_back(v);
    }

    //Cycle detection using DFS Traversal.
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsVisisted;

    for(int i=1; i<=vertices; i++){
        if(!visited[i]){
            bool cycleDetected = detectCycleDFS(i, visited, dfsVisisted, adjList);

            if(cycleDetected == true){
                cout<<"Cycle is present in the graph"<<endl;
                return 0;
            }
        }
    }

    cout<<"Cycle is not present in the graph"<<endl;

    return 0;
}