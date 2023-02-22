//Depth First Traversal of Graph.
/*
Algorithm :
    1. First we need to create adjancency list.
    2. We need a data structure (Map) to store visited nodes.
    3. Time Complexity : O(vertices+edge), Space Complexity : O(vertices).
*/
#include<iostream>
#include<set>
#include<vector>
#include<unordered_map>
using namespace std;

void DFS(unordered_map<int, vector<int>> &adjList, unordered_map<int, bool> &visited, int node, vector<int> &component){
    component.push_back(node);
    visited[node] = true;

    for(auto i : adjList[node]){
        if(!visited[i]){
            DFS(adjList, visited, i, component);
        }
    }
}

int main()
{
    int vertices;
    cout<<"Enter the number of vertices"<<endl;
    cin>>vertices;

    int edges;
    cout<<"Enter the number of edges"<<endl;
    cin>>edges;

    //Taking input.
    vector<pair<int,int>> graph;

    for(int i=0; i<edges; i++){
        int u, v;
        cin>>u>>v;

        graph.push_back(make_pair(u,v));
    }

    //Creating adjacency list (undirected graph).
    unordered_map<int, vector<int>> adjList; 
    for(int i=0; i<edges; i++){
        int u = graph[i].first;
        int v = graph[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    //DFS Traversal.
    unordered_map<int, bool> visited;

    vector<vector<int>> ans;

    for(int i=0; i<vertices; i++){
        if(!visited[i]){
            vector<int> component;
            DFS(adjList, visited, i, component);
            ans.push_back(component);
        }
    }

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}