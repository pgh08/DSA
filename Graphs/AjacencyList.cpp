#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

//To make code more generic we make use of template.
template <typename T>

class Graphs{
    public:
        unordered_map<T, list<T>> adjList;

        void addEdge(T u, T v, bool direction){
            //direction = false -> undirected.  
            //direction = true -> directed.

            adjList[u].push_back(v);

            if(direction == false){
                adjList[v].push_back(u);
            }
        }
        
        void printAdjListList(){
            for(auto i : adjList){
                cout<<i.first<<" -> ";
                for(auto j : i.second){
                    cout<<j<<", ";
                }
                cout<<endl;
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

    //While calling the objaect we need to required data type in <>, Example "Class_Name<datatype> Object_Name".
    Graphs<int> g;

    for(int i=0; i<edges; i++){
        int u, v;
        cin>>u>>v;

        //Creating undirected graph.
        g.addEdge(u, v, false);
    }

    //Printing Graph.
    g.printAdjListList();

    return 0;
}