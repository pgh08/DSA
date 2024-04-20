// You are given a 0-indexed m x n binary matrix land where a 0 represents a hectare of forested land and a 1 represents a hectare of farmland.
// To keep the land organized, there are designated rectangular areas of hectares that consist entirely of farmland. These rectangular areas are called groups. 
// No two groups are adjacent, meaning farmland in one group is not four-directionally adjacent to another farmland in a different group.
// lLand can be represented by a coordinate system where the top left corner of land is (0, 0) and the bottom right corner of land is (m-1, n-1). 
// Find the coordinates of the top left and bottom right corner of each group of farmland. 
// A group of farmland with a top left corner at (r1, c1) and a bottom right corner at (r2, c2) is represented by the 4-length array [r1, c1, r2, c2].

/* 
Approach : 1. Find the land and do dfs to mark all the piece of lands connected to it.
           2. While marking keep minimum of row and col which indicates leftmost top corner of that piece of land.
           3. While marking keep maximum of row and col which indicates rightmost bottom corner of that piece of land.
           4. Push the above into an answer array which stores all the farmlands.
           5. Time Complexity : O(n^2), Space Complexity : O(1).
*/
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int row[4] = {0, 0, -1, 1};
int col[4] = {-1, 1, 0, 0};

bool isSafe(int &r, int &c, int &m, int &n){
    if(r >= 0 && r < m && c >= 0 && c < n){
        return true;
    }
    
    return false;
}

void dfs(vector<vector<int>> &land, int i, int j, int &m, int &n, vector<int> &landDimension){
    landDimension[0] = min(landDimension[0], i);
    landDimension[1] = min(landDimension[1], j);
    landDimension[2] = max(landDimension[2], i);
    landDimension[3] = max(landDimension[3], j);

    land[i][j] = 0;

    for(int k=0; k<4; k++){
        int r = i + row[k];
        int c = j + col[k];

        if(isSafe(r, c, m, n) && land[r][c] == 1){
            dfs(land, r, c, m, n, landDimension);
        }
    }
}

vector<vector<int>> getAllFarmlands(vector<vector<int>> &land, int &m, int &n){
    vector<vector<int>> ans;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(land[i][j] == 1){
                vector<int> landDimension(4, INT_MIN);
                landDimension[0] = landDimension[1] = INT_MAX;

                dfs(land, i, j, m, n, landDimension);

                ans.push_back(landDimension);
            }
        }
    }

    return ans;
}

int main()
{
    int m, n;
    cout<<"Enter the number of rows and columns of the land"<<endl;
    cin>>m>>n; // 3 3.

    vector<vector<int>> land(m, vector<int> (n, 0));
    cout<<"Enter the value of land row wise"<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>land[i][j];
            /* 
                1 0 0
                0 1 1
                0 1 1
            */
        }
    }

    vector<vector<int>> farmlands = getAllFarmlands(land, m, n);

    cout<<"Co-ordinates of all farmlands are : "<<endl;
    for(int i=0; i<farmlands.size(); i++){
        cout<<"Farmland "<<(i+1)<<" : ";
        for(int j=0; j<4; j++){
            cout<<farmlands[i][j]<<" ";
            /* 
                0 0 0 0
                1 1 2 2
            */
        }
        cout<<endl;
    }

    return 0;
}