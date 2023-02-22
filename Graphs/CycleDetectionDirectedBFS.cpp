//Given a Directed graph, find whether the graph has cycle.
/*
Algorithm :
    1. Use Kahn's algorithm.
    2. If number of elements in topological sort is equal to number of vertices then graph doesn't contain cycle else contains cycle.
    3. Time Complexity : O(V+E), Space Complexity : O(V).
*/
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_map<int,vector<int>> adjList;
    int vertices,edges;
    cout<<"Enter the number of vertices"<<endl;
    cin>>vertices;

    cout<<"Enter the number of edges"<<endl;
    cin>>edges;

    //Creating Ajacency List for Directed graph.
    for(int i=0; i<edges; i++){
        int u, v;
        cin>>u>>v;

        adjList[u].push_back(v);
    }

    //Kahn's Algorithm.
    //Creating Indegree.
    vector<int> Indegree(vertices,0);
    for(auto i : adjList){
        for(auto j : i.second){
            Indegree[j]++;
        }
    }

    //Push all the nodes which has Indegree as zero.
    queue<int> q;
    for(int i=1; i<=vertices; i++){
        if(Indegree[i] == 0){
            q.push(i);
        }
    }

    //Regular BFS Traversal with Topological element count.
    int count = 0;
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        count++;

        for(auto i : adjList[frontNode]){
            Indegree[i]--;

            if(Indegree[i] == 0){
                q.push(i);
            }
        }
    }

    if(count == vertices){
        cout<<"Cycle is not present in the graph"<<endl;
    }
    else{
        cout<<"Cycle is present in the graph"<<endl;
    }

    return 0;
}