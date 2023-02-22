#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

void getTopologicalSort(int node, unordered_map<int,bool> &visited, unordered_map<int,vector<int>> &adjList, stack<int> &st){
    visited[node] = true;

    for(auto neighbour : adjList[node]){
        if(!visited[neighbour]){
            getTopologicalSort(neighbour, visited, adjList, st);
        }
    }

    //If DFS call is returning from the recursive call push it into stack.
    st.push(node);
}

int main()
{
    unordered_map<int,vector<int>> adjList;
    int vertices, edges;
    cout<<"Enter the number of vertices"<<endl;
    cin>>vertices;

    cout<<"Enter the number of edges"<<endl;
    cin>>edges;

    //Creating Adjacency List of Directed Graph.
    for(int i=0; i<edges; i++){
        int u, v;
        cin>>u>>v;

        adjList[u].push_back(v);
    }

    //Topological Sort using DFS.
    unordered_map<int,bool> visited;
    stack<int> st;

    for(int i=1; i<=vertices; i++){
        if(!visited[i]){
            getTopologicalSort(i, visited, adjList, st);
        }
    }

    //Printing ans.
    cout<<"Topological sort is :"<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;

    return 0;
}