//Given a Directed Acyclic Graph (DAG) find the shortest path from source node to all nodes.
/*
Algorithm :
    1. Contruct a Topological sort stack.
    2. Use topological sort array to update distance array.
    3. Update distance if the element is not INFINITY or it's value is greater than current computed value.
    4. For additional information refer notes.
    5. Time Complexity : O(V+E), Space Complexity : O(V).
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<limits.h>
using namespace std;

void getTopologicalSort(int node, vector<int> &visited, stack<int> &st, unordered_map<int,vector<pair<int,int>>> &adjList){
    visited[node] = 1;

    for(auto i : adjList[node]){
        if(!visited[i.first]){
            getTopologicalSort(i.first, visited, st, adjList);
        }
    }
    st.push(node);
}

int main()
{
    int vertices, edges;
    cout<<"Enter the number of vertices"<<endl;
    cin>>vertices;

    cout<<"Enter the number of edges"<<endl;
    cin>>edges;

    //Creating Adjacency List for Directed graph.
    cout<<"Enter the input in the order source, destination and respective weight"<<endl;
    unordered_map<int,vector<pair<int,int>>> adjList;
    for(int i=0; i<edges; i++){
        int u, v, weight;
        cin>>u>>v>>weight;

        adjList[u].push_back(make_pair(v,weight));
    }

    //Topological Sort.
    vector<int> visited(vertices,0);
    stack<int> st;

    for(int i=0; i<vertices; i++){
        if(!visited[i]){
            getTopologicalSort(i, visited, st, adjList);
        }
    }

    //Creating the distance array.
    int source;
    cout<<"Enter the source from which shortest path will be found"<<endl;
    cin>>source;

    vector<int> distance(vertices, INT_MAX);
    distance[source] = 0;

    while(!st.empty()){
        int top = st.top();
        st.pop();

        if(distance[top] != INT_MAX){
            for(auto i : adjList[top]){
                if((distance[top] + i.second) < distance[i.first]){
                    distance[i.first] = distance[top] + i.second;
                }
            }
        }
    }

    //Printing the Distance array.
    int n = distance.size();
    for(int i=0; i<n; i++){
        cout<<source<<"-->"<<i<<" = "<<distance[i]<<endl;
    }
    cout<<endl;

    return 0;
}