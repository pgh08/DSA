// Given an m x n 2D binary grid which represents a map of '1's (land) and '0's (water), return the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
// You may assume all four edges of the grid are all surrounded by water.
// Time Complexity : O(n^2), Space Complexity : O(1).
#include<iostream>
#include<vector>
using namespace std;

const int row[4] = {0, 0, -1, 1};
const int col[4] = {-1, 1, 0, 0};

bool isSafe(int r, int c, int &m, int &n){
    if(r >= 0 && r < m && c >= 0 && c < n){
        return true;
    }

    return false;
}

void dfs(vector<vector<int>> &grid, int i,int j, int &m, int &n){
    grid[i][j] = 0;

    for(int k=0; k<4; k++){
        int r = i+row[k];
        int c = j+col[k];

        if(isSafe(r, c, m, n) && grid[r][c] == 1){
            dfs(grid, r, c, m, n);
        }
    }
}

int getIslandCount(vector<vector<int>> &grid, int &m, int &n){
    int count = 0;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 1){
                count++;
                dfs(grid, i, j, m, n);
            }
        }
    }

    return count;
}

int main()
{
    int m, n;
    cout<<"Enter the value of m and n"<<endl;
    cin>>m>>n; // 4 5.

    vector<vector<int>> grid(m, vector<int> (n, 0));
    cout<<"Enter the value of the grid"<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
            /* 
                1 1 0 0 0
                1 1 0 0 0
                0 0 1 0 0
                0 0 0 1 1
            */
        }
    }

    int ans = getIslandCount(grid, m, n);

    cout<<"Number of islands : "<<ans<<endl; // 3.

    return 0;
}