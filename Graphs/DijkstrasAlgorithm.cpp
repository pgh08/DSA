//Given a graph use Dijkstra's Algorithm to find the minumum distance from source node to all other nodes.
/*
Algorithm :
    1. Use set to store the distance and node pair sorted by distance.
    2. Pick a node find distance of all the other neighbours of that node.
    3. If the distance, node pair already present in the set and the distance in that pair is greater than the current distance then remove that pair add new pair.
    4. Time Complexity : O(E*log(V)), Space Complexity : O(V).
*/
#include<iostream>
#include<unordered_map>
#include<set>
#include<vector>
#include<limits.h>
using namespace std;

void doDijkstra(int &source, unordered_map<int,vector<pair<int,int>>> &adjList, vector<int> &distance){
    set<pair<int,int>> distanceNodeSet;
    distance[source] = 0;
    distanceNodeSet.insert(make_pair(0,0));

    while(!distanceNodeSet.empty()){
        //TopNode is always be the one with the least distance.
        auto top = *(distanceNodeSet.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        distanceNodeSet.erase(distanceNodeSet.begin());

        //Traverse on neighbours.
        for(auto neighbour : adjList[topNode]){
            if(nodeDistance + neighbour.second < distance[neighbour.first]){
                auto record = distanceNodeSet.find(make_pair(distance[neighbour.first],neighbour.first));

                if(record != distanceNodeSet.end()){
                    distanceNodeSet.erase(record);
                }

                //Update distance.
                distance[neighbour.first] = nodeDistance + neighbour.second;
                //Insert record into set.
                distanceNodeSet.insert(make_pair(distance[neighbour.first],neighbour.first));
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

    //Creating the Ajacency List.
    unordered_map<int,vector<pair<int,int>>> adjList;
    cout<<"Enter the input in the order node1, node2 and distance between them"<<endl;
    for(int i=0; i<edges; i++){
        int u, v, weight;
        cin>>u>>v>>weight;

        adjList[u].push_back(make_pair(v,weight));
        adjList[v].push_back(make_pair(u,weight));
    }

    //Dijkstra's Algorithm.
    int source;
    cout<<"Enter the source node"<<endl;
    cin>>source;
    vector<int> distance(vertices,INT_MAX);

    doDijkstra(source, adjList, distance);

    //Printing answer.
    for(int i=0; i<vertices; i++){
        cout<<source<<"-->"<<i<<" = "<<distance[i]<<endl;
    }
    cout<<endl;

    return 0;
}