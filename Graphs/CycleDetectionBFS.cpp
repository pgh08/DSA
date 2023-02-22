#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
using namespace std;

void makeAdjList(int u, int v, unordered_map<int, vector<int>> &adjList, bool direction){
    adjList[u].push_back(v);

    if(direction == false){
        adjList[v].push_back(u);
    }
}

bool isCyclicBFS(int source, unordered_map<int, bool> &visited, unordered_map<int, vector<int>> &adjList){
    unordered_map<int,int> parent;

    parent[source] = -1;

    visited[source] = true;
    queue<int> q;
    q.push(source);

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        for(auto neighbour : adjList[frontNode]){
            if(visited[neighbour] == true && neighbour != parent[frontNode]){
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = frontNode;
            }
        }
    }
    return false;
}

int main()
{
    unordered_map<int, vector<int>> adjList;

    int vertices, edges;
    cout<<"Enter the number of vertices"<<endl;
    cin>>vertices;

    cout<<"Enter the number of edges"<<endl;
    cin>>edges;

    for(int i=0; i<edges; i++){
        int u,v;
        cin>>u>>v;

        makeAdjList(u, v, adjList, false);
    }

    //To Handale disconnected componenets.
    unordered_map<int, bool> visited;

    for(int i=0; i<vertices; i++){
        if(!visited[i]){
            bool ans = isCyclicBFS(i, visited, adjList);
            if(ans == true){
                cout<<"Cycle is present"<<endl;
                return 0;
            }
        }
    }

    cout<<"Cycle is not present"<<endl;

    return 0;
}