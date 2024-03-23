// Given the number of nodes, edges and connection between nodes. Find the number of ways in which we can color the map such that no
// adjacent nodes can be of same color. We can only pick colors from {Red, Blue, Green}.
#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
#include<set>
using namespace std;

bool isSafe(unordered_map<int,vector<int>> &adjList, map<int,int> &colors, int &currV, int &V, int color){
    for(auto node : adjList[currV]){
        if(colors[node] == color){
            return false;
        }
    }

    return true;
}

int colorGraph(unordered_map<int,vector<int>> &adjList, map<int,int> &colors, int totalColors, int currV, int &V){
    // Base Case.
    if(currV >= V){
        return 1;
    }

    int ways = 0;

    // Try Different Color for current Vertice.
    for(int col=1; col<=totalColors; col++){

        // Check if the color is safe to take.
        if(isSafe(adjList, colors, currV, V, col)){

            // If the current choice of color satisfies then move on to next vertice.
            colors[currV] = col;

            ways += colorGraph(adjList, colors, totalColors, currV+1, V);

            // Backracking.
            colors[currV] = 0;
        }
    }

    return ways;
}

int solve(vector<vector<int>> &edges, int &V, int &e){
    
    // Creating an adjacency list.
    unordered_map<int,vector<int>> adjList;

    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    map<int,int> colors;
    int ans = colorGraph(adjList, colors, 3, 0, V);

    return ans;
}

int main()
{
    int v, e;
    cout<<"Enter the value of number of nodes and edges respectively"<<endl;
    cin>>v>>e;

    vector<vector<int>> edges(e, vector<int> (2, 0));
    cout<<"Enter the connections"<<endl;
    for(int i=0; i<e; i++){
        cin>>edges[i][0]>>edges[i][1];
    }

    cout<<solve(edges, v, e)<<endl;

    return 0;
}