//Given the graph find all the Articulation Points.
/*
Algorithm : 
    1. We need 3 arrays namely discoveryTime, earliestPossibleTime, visited.
    2. Keep the timer and keep updating it till all nodes traversed.
    3. Update discoveryTime, earliestPossibleTime and parent and also visited array.
    4. If neighbour node is already visited then it has backEdge then update earliestPossibleTime[node] = min(earliestPossibleTime, discoveryTime[neighbour]).
    5. If neighbour equals to parent then ignore the updation.
    6. When returning earliestPossibleTime[node] = min(earliestPossibleTime[node], earliestPossibleTime[child]).
    7. Articulation Point is valid only if earliestPossibleTime[neighbour] >= discoveryTime[node] && parent != -1.
    8. To handel starting point, Articulation Point is also valid when parent == -1 && numberOfNeighbours > 1.
    8. Time Complexity : O(V+E), Space Complexity : O(V).
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void findArticulationPointDFS(int node, int parent, int timer, vector<int> &discoveryTime, vector<int> &earliestPossibleTime, vector<int> &articulationPoints, unordered_map<int,bool> &visited, 
                                unordered_map<int,vector<int>> &adjList){
    visited[node] = true;
    discoveryTime[node] = earliestPossibleTime[node] = timer++;
    int child = 0;

    for(auto neighbour : adjList[node]){
        if(neighbour == parent){
            continue;
        }
        if(!visited[neighbour]){
            findArticulationPointDFS(neighbour, node, timer, discoveryTime, earliestPossibleTime, articulationPoints, visited, adjList);

            //While returning update earliestPossibleTime.
            earliestPossibleTime[node] = min(earliestPossibleTime[node], discoveryTime[neighbour]);

            //Checking for articulation points.
            if(earliestPossibleTime[neighbour] >= discoveryTime[node] && parent != -1){
                articulationPoints.push_back(node);
            }
            child++;
        }
        else{
            earliestPossibleTime[node] = min(earliestPossibleTime[node], discoveryTime[neighbour]);
        }
    }

    //Handeling starting point.
    if(parent == -1 && child > 1){
        articulationPoints.push_back(node);
    }
}
    

int main()
{
    int vertices, edges;
    cout<<"Enter the number of vertices"<<endl;
    cin>>vertices;

    cout<<"Enter the number of edges"<<endl;
    cin>>edges;
    
    //Creating a Adjancency List.
    unordered_map<int,vector<int>> adjList;
    for(int i=0; i<edges; i++){
        int u, v;
        cin>>u>>v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int timer = 0;
    vector<int> discoveryTime(vertices,-1);
    vector<int> earliestPossibleTime(vertices,-1);
    vector<int> articulationPoints;
    int parent = -1;
    unordered_map<int,bool> visited;

    //Storing Articular Points using DFS.
    for(int i=0; i<vertices; i++){
        if(!visited[i]){
            findArticulationPointDFS(i, parent, timer, discoveryTime, earliestPossibleTime, articulationPoints, visited, adjList);
        }
    }

    //Printing Articulation Points.
    cout<<"Articulation Points are : "<<endl;
    for(int i=0; i<articulationPoints.size(); i++){
        cout<<articulationPoints[i]<<" ";
    }
    cout<<endl;

    return 0;
}