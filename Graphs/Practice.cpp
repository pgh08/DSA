#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
using namespace std;

void dfs(unordered_map<int,vector<int>> &adjList, vector<int> &visited, stack<int> &st, int node){
    visited[node] = 1;

    for(auto i : adjList[node]){
        if(!visited[i]){
            dfs(adjList, visited, st, i);
        }
    }

    st.push(node);
}

int main()
{
    unordered_map<int,vector<int>> adjList;
    int vertices, edges;
    cout<<"Enter the number of vertices and edges"<<endl;
    cin>>vertices>>edges;

    for(int i=0; i<edges; i++){
        int u,v;
        cin>>u>>v;

        adjList[u].push_back(v);
    }

    vector<int> visited(vertices, 0);
    stack<int> st;

    for(int i=0; i<vertices; i++){
        if(!visited[i]){
            dfs(adjList, visited, st, i);
        }
    }

    cout<<"Topological sort is : "<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;

    return 0;
}