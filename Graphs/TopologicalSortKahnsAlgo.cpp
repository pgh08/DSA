//Given a Directed acyclic graph find the topological sort using Kahn's Algorithm (BFS).
/*
Algorithm :  
    1. Create a Ajdacency List for directed graph.
    2. Find the Indegree of all the graph nodes.
    3. In BFS push only elements which have Indegree equal to zero.
    4. Follow regular BFS procedure and push frontNode to answer each time.
    5. Update the Indegree array after each iteration.
    6. Time Complexity : O(V+E), Space Complexity : O(V).
*/
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_map<int,vector<int>> adjList;
    int vertices, edges;
    cout<<"Enter the number of vertices"<<endl;
    cin>>vertices;

    cout<<"Enter the number of edges"<<endl;
    cin>>edges;

    //Creating Adjacency List for Directed graph.
    for(int i=0; i<edges; i++){
        int u, v;
        cin>>u>>v;

        adjList[u].push_back(v);
    }

    //Kahn's Algorithm.
    //Finding Indegree.
    vector<int> Indegree(vertices,0);

    for(auto i : adjList){
        for(auto j : i.second){
            Indegree[j]++;
        }
    }

    //Storing nodes whose Indegree is zero.
    queue<int> q;
    for(int i=1; i<=vertices; i++){
        if(Indegree[i] == 0){
            q.push(i);
        }
    }

    //Regular BFS Traversal.
    vector<int> ans;
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        //Update Indegree values of frontNode's neighbour.
        for(auto i : adjList[frontNode]){
            Indegree[i]--;
            if(Indegree[i] == 0){
                q.push(i);
            }
        }
    }

    //Printing Topologocial Sort datas.
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}