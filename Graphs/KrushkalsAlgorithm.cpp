//Given a graph implement Krushkal's Algorithm.
//In this code I implemented discjoint set, path compression algorithm.
/*
Algorithm :
    1. Initialize parent to it's index value and rank array to initially zero.
    2. Implement findParent function using recursion with base case as parent[node] = node.
    3. Use path compression to save time in above method.
    4. Find union of all node pairs :
       --> If rank[node1] < rank[node2] then parent[node1] = node2;
       --> if rank[node1] > rank[node2] then parent[node2] = node1;
       --> Else (in case both node's rank is equal) parent[node1] = node2 or parent[node2] = node1.
    5. Kruskal's Algorithm : Sort edges based on the weights then check whether both edges have same parent, if so ignore those nodes else make union of those.
    6. Time Complexity : O(E*log(E)), Space Complexity : O(V).
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(vector<int> &a, vector<int> &b){
    //Weight is in 2nd index in each row.
    return a[2] < b[2];
}

int findParent(int node, vector<int> &parent){
    //Parent[node] = node is only for root node.
    if(parent[node] == node){
        return node;
    }
    return parent[node] = findParent(parent[node], parent);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findParent(u, parent);
    v = findParent(v, parent);

    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(rank[u] > rank[v]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}

int main()
{
    int vertices, edges;    
    cout<<"Enter the number of vertices"<<endl;
    cin>>vertices;

    cout<<"Enter the number of egdes"<<endl;
    cin>>edges;

    //Creating a edges vector.
    cout<<"Enter the input in the format node1, node2 and their respective weights"<<endl;
    vector<vector<int>> graph;
    for(int i=0; i<edges; i++){
        int u, v, weight;
        cin>>u>>v>>weight;

        graph.push_back({u,v,weight});
    }

    //Sorting based on weight using custom comaprator.
    sort(graph.begin(), graph.end(), compare);

    //Creating funtion for finding Parent, Union.
    vector<int> parent(vertices);
    vector<int> rank(vertices);

    //Initializing parent and rank array.
    for(int i=0; i<vertices; i++){
        parent[i] = i;
        rank[i] = 0;
    }

    //Finding minimum weight.
    int minWeight = 0;

    for(int i=0; i<edges; i++){
        int u = findParent(graph[i][0], parent);
        int v = findParent(graph[i][1], parent);
        int weight = graph[i][2];

        if(u != v){
            minWeight += weight;
            unionSet(u, v, parent, rank);
        }
    }

    cout<<"Minimum weight of spanning tree is : "<<minWeight<<endl;

    return 0;
}