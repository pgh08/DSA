// Given grid of obstacle where 1 represents the obstacle and 0 represents the empty space. Robot can move only down or right, count the number of unique ways to reach destination (grid[n-1][m-1]) from source (grid[0][0]). 
// Recursive Approach : Time Complexity : O(2^(n*m)), Space Complexity : O(m+n).
// Top Down Approach : Time Complexity : O(n*m), Space Complexity : O(m*n).
#include<iostream>
#include<vector>
using namespace std;

int solveRecursively(vector<vector<int>> &obstacleGrid, int &n, int &m, int row, int col){
    // Base Case.
    if(row == n-1 && col == m-1){
        return 1;
    }

    int ans = 0;
    // Go down.
    if((row < n && col < m) && obstacleGrid[row][col] != 1){
        ans += solveRecursively(obstacleGrid, n, m, row+1, col);
    }

    // Go left.
    if((row < n && col < m) && obstacleGrid[row][col] != 1){
        ans += solveRecursively(obstacleGrid, n, m, row, col+1);
    }

    return ans;
}

int solveTopDownMemo(vector<vector<int>> &obstacleGrid, int &n, int &m, int row, int col, vector<vector<int>> &dp){
    // Base Case.
    if(row == n-1 && col == m-1){
        return 1;
    }
    if(dp[row][col] != -1){
        return dp[row][col];
    }

    int ans = 0;
    // Go down.
    if((row < n && col < m) && obstacleGrid[row][col] != 1){
        ans += solveTopDownMemo(obstacleGrid, n, m, row+1, col, dp);
    }

    // Go left.
    if((row < n && col < m) && obstacleGrid[row][col] != 1){
        ans += solveTopDownMemo(obstacleGrid, n, m, row, col+1, dp);
    }

    return dp[row][col] = ans;
}

int main()
{
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();

    // Recursive Approach.
    // int ans = solveRecursively(obstacleGrid, n, m, 0, 0);

    // Top Down Approach.
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    int ans = solveTopDownMemo(obstacleGrid, n, m, 0, 0, dp);

    cout<<"Total to number of ways to reach destination are : "<<ans<<endl;

    return 0;
}