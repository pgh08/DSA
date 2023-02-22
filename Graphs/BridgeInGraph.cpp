//Given a graph find the bridges.
/* 
Algorithm :
    1. We need 3 arrays namely discoveryTime, earliestPossibleTime, visited.
    2. Keep the timer and keep updating it till all nodes traversed.
    3. Update discoveryTime, earliestPossibleTime and parent and also visited array.
    4. If neighbour node is already visited then it has backEdge then update earliestPossibleTime[node] = min(earliestPossibleTime, discoveryTime[neighbour]).
    5. If neighbour equals to parent then ignore the updation.
    6. When returning earliestPossibleTime[node] = min(earliestPossibleTime[node], earliestPossibleTime[child]).
    7. To check bridge if earliestPossibleTime[neighbour] greater than discoveryTime[node] then bridge is present.
    8. Time Complexity : O(V+E), Space Complexity : O(V).
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void dfsBridge(int node, int parent, int timer, vector<int> &discoveryTime, vector<int> &earliestPossibleTime, unordered_map<int,bool> &visited, unordered_map<int,vector<int>> &adjList, vector<vector<int>> &ans){
    visited[node] = true;
    discoveryTime[node] = earliestPossibleTime[node] = timer++;

    for(auto neighbour : adjList[node]){
        if(neighbour == parent){
            continue;
        }
        if(!visited[neighbour]){
            dfsBridge(neighbour, node, timer, discoveryTime, earliestPossibleTime, visited, adjList, ans);
            earliestPossibleTime[node] = min(earliestPossibleTime[node], earliestPossibleTime[neighbour]);

            //Check for bridge.
            if(earliestPossibleTime[neighbour] > discoveryTime[node]){
                ans.push_back({node, neighbour});
            }
        }   
        else{
            //BackEdge case.
            earliestPossibleTime[node] = min(earliestPossibleTime[node], discoveryTime[neighbour]);
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

    //Creating adjList.
    unordered_map<int,vector<int>> adjList;
    for(int i=0; i<edges; i++){
        int u, v;
        cin>>u>>v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    //Creating required arrays for algorithm.
    vector<int> discoveryTime(vertices, -1);
    vector<int> earliestPossibleTime(vertices, -1);
    unordered_map<int,bool> visited;
    int parent = -1;
    int timer = 0;

    vector<vector<int>> ans;
    for(int i=0; i<vertices; i++){
        if(!visited[i]){
            dfsBridge(i, parent, timer, discoveryTime, earliestPossibleTime, visited, adjList, ans);
        }
    }

    cout<<""<<endl;
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
}