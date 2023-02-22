//Given a directed graph with negative weights find the shortest path from the source node.
/*
Algorithm :
    1. Update the distance (V-1) times when distance[node1] + weight < distance[node2].
    2. If distance array gets updated even after (V-1) times then negative cycle is present.
    3. Time Complexity : O(V*E), Space Complexity : O(V).
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main()
{
    int vertices, edges;
    cout<<"Enter the number of vertices"<<endl;
    cin>>vertices;

    cout<<"Enter the number of edges"<<endl;
    cin>>edges;

    //Creating Adjancency List.
    cout<<"Enter the input in the order node1, node2 and weight"<<endl;
    vector<pair<int,pair<int,int>>> adjList;
    for(int i=0; i<edges; i++){
        int u, v, weight;
        cin>>u>>v>>weight;

        adjList.push_back(make_pair(u,make_pair(v,weight)));
    }

    //Bellman Ford Algorithm.
    vector<int> distance(vertices+1, 1e9);

    int source;
    cout<<"Enter the source node"<<endl;
    cin>>source;
    distance[source] = 0;

    for(int i=1; i<=vertices; i++){
        //Traverse on edges of the list.
        for(auto j : adjList){
            if((distance[j.first] != 1e9) && (distance[j.first] + j.second.second < distance[j.second.first])){
                distance[j.second.first] = distance[j.first] + j.second.second;
            }
        }
    }

    cout<<"Shortest distance from source node "<<source<<" to all node is : "<<endl;
    for(int i=1; i<=vertices; i++){
        cout<<source<<"-->"<<i<<" = "<<distance[i]<<endl;
    }
    cout<<endl;

    return 0;
}