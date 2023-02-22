//Breadth First Traversal of Graph.
/*
Algorithm :
    1. We need a data structure (Map) to store visited nodes.
    2. One queue is required for keeping track of adjacent elements of a particular node.
    3. Time Complexity : O(n+e), Space Complexity : O(n+e).
*/
#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<set>
using namespace std;

template <typename T>
class Graphs{
    public:
        unordered_map<T, set<T>> adjList;

        void addEdge(T u, T v, bool direction){
            
            adjList[u].insert(v);

            if(direction == false){
                adjList[v].insert(u);
            }
        }

        void printAdjList(){
            for(auto i : adjList){
                cout<<i.first<<" --> ";
                for(auto j : i.second){
                    cout<<j<<", ";
                }
                cout<<endl;
            }
        }

        void BFS(unordered_map<int, bool> &visited, vector<int> &ans, int node){
            queue<int> q;
            q.push(node);
            visited[node] = true;

            while(!q.empty()){
                int frontNode = q.front();
                q.pop();

                ans.push_back(frontNode);

                for(auto i : adjList[frontNode]){
                    if(!visited[i]){
                        q.push(i);
                        visited[i] = true; 
                    }
                }
            }
        }

        void BFSTraverse(int vertex, vector<int> &ans){
            unordered_map<int, bool> visited;
            
            for(int i=0; i<vertex; i++){
                if(!visited[i]){
                    BFS(visited, ans, i);
                }
            }
        }
};

int main()
{
    int vertices;
    cout<<"Enter the number of vertices"<<endl;
    cin>>vertices;

    int edges;
    cout<<"Enter the number of edges"<<endl;
    cin>>edges;

    Graphs<int> g;

    //Creating Graph.
    for(int i=0; i<edges; i++){
        int u, v;
        cin>>u>>v;

        g.addEdge(u, v, false);
    }

    g.printAdjList();

    vector<int> ans;
    g.BFSTraverse(vertices, ans);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}