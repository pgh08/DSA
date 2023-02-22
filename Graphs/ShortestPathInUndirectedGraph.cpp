//Given an Undirected graph find the shortest path between source and destination.
/*
Algorithm :
    1. First find the Adjacency List.
    2. Do BFS Traversal and construct a parent array.
    3. Find the parent of destination place using parent array till we end up with source.
    4. Time Complexity : O(V+E), Space Complexity : O(V).
*/
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

void getParent(int node, vector<int> &visited, vector<int> &parent, unordered_map<int,vector<int>> &adjList){
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    parent[node] = -1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        //Updating parent.
        for(auto i : adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
                parent[i] = frontNode;
            }
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

    //Creating the Adjacency List.
    unordered_map<int,vector<int>> adjLsit;
    for(int i=0; i<edges; i++){
        int u, v;
        cin>>u>>v;

        adjLsit[u].push_back(v);
        adjLsit[v].push_back(u);
    }

    //BFS Traversal for creating parent array.
    vector<int> visited(vertices,0);
    vector<int> parent(vertices);

    for(int i=1; i<=vertices; i++){
        if(!visited[i]){
            getParent(i ,visited, parent, adjLsit);
        }
    }

    //Getting shortest path using parent array.
    int source, destination;
    cout<<"Enter source and destination to find the shortest path"<<endl;
    cin>>source>>destination;

    vector<int> ans;
    int currNode = destination;
    ans.push_back(currNode);

    while(currNode != source){
        currNode = parent[currNode];
        ans.push_back(currNode);
    }

    //Printing the shortest path.
    int n = ans.size();
    for(int i=n-1; i>=0; i--){
        cout<<ans[i];
        if(i != 0){
            cout<<"-->";
        }
    }
    cout<<endl;

    return 0;
}