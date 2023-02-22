//Given the grapg find all the strongly connected component.
/*
Algorithm :
    1. Get Topological sort using DFS.
    2. Transpose graph that is reverse direction of all the edges in the graph.
    3. Do DFS and if visited store all the nodes before in the answer array.
    4. Time Complexity : O(V+E), Space Complexity : O(V).
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

void dfsTopologicalSort(int node, stack<int> &dfsStack, unordered_map<int,bool> &visited, unordered_map<int,vector<int>> &adjList){
    visited[node] = true;

    for(auto neighbour : adjList[node]){
        if(!visited[neighbour]){
            dfsTopologicalSort(neighbour, dfsStack, visited, adjList);
        }
    }
    dfsStack.push(node);
}

void dfsFindStrongConnections(int node, vector<int> &component, unordered_map<int,bool> &visited, unordered_map<int,vector<int>> &transpose){
    visited[node] = true;
    component.push_back(node);

    for(auto neighbour : transpose[node]){
        if(!visited[neighbour]){
            dfsFindStrongConnections(neighbour, component, visited, transpose);
        }
    }
}

int main()
{
    int vertices, edges;
    cout<<"Enter the number of vertices"<<endl;
    cin>>vertices;

    cout<<"Enter the number of edges"<<endl;
    cin>>edges;

    //Create Adjacency List.
    unordered_map<int,vector<int>> adjList;
    for(int i=0; i<edges; i++){
        int u, v;
        cin>>u>>v;

        adjList[u].push_back(v);
    }

    //Topological Sort.
    unordered_map<int,bool> visited;
    stack<int> dfsStack;

    for(int i=0; i<vertices; i++){
        if(!visited[i]){
            dfsTopologicalSort(i, dfsStack, visited, adjList);
        }
    }

    //Create a Transpose Graph.
    unordered_map<int,vector<int>> transpose;
    for(int i=0; i<vertices; i++){
        visited[i] = false;
        for(auto neighbour : adjList[i]){
            transpose[neighbour].push_back(i);
        }
    }

    //Storing different Strongly Connected Graph using DFS.
    vector<vector<int>> ans;
    while(!dfsStack.empty()){
        vector<int> component;
        int top = dfsStack.top();
        dfsStack.pop();

        if(!visited[top]){
            dfsFindStrongConnections(top, component, visited, transpose);
            ans.push_back(component);
        }
        component.clear();
    }

    //Printing Strongly connected components.
    cout<<"Strongly Connected componentes are : "<<endl;
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
}