// Given the 2D matrix of zeros and ones find the maximum size submatrix which consists of only ones.
// Recursive Approach : Time Complexity : O((rows*cols)^3), Space Complexity : O(rows*cols).
// Top Down Memoization Approach : Time Complexity : O(rows*cols), Space Complexity : O(rows*cols).
// Bottom Up Approach : Time Complexity : O(rows*cols), Space Complexity : O(rows*cols).
// Space Optimized Approach : Time Complexity : O(rows*cols), Space Complexity : O(cols).
// More Space Optimized Approach : Time Complexity : O(rows*cols), Space Complexity : O(1).
#include<iostream>
#include<vector>
using namespace std;

int solveRecursively(vector<vector<int>> &matrix, int &rows, int &cols, int i, int j, int &maxi){
    // Base Case.
    if(i >= rows || j >= cols){
        return 0;
    }

    int right = solveRecursively(matrix, rows, cols, i, j+1, maxi);
    int diagonal = solveRecursively(matrix, rows, cols, i+1, j+1, maxi);
    int down = solveRecursively(matrix, rows, cols, i+1, j, maxi);

    if(matrix[i][j] == 1){
        int ans = 1 + min(right, min(diagonal, down));
        maxi = max(ans, maxi);
        return ans;
    }
    else{
        return 0;
    }
}

int solveTopDownMemo(vector<vector<int>> &matrix, int &rows, int &cols, int i, int j, int &maxi, vector<vector<int>> &dp){
    // Base Case.
    if(i >= rows || j >= cols){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int right = solveTopDownMemo(matrix, rows, cols, i, j+1, maxi, dp);
    int diagonal = solveTopDownMemo(matrix, rows, cols, i+1, j+1, maxi, dp);
    int down = solveTopDownMemo(matrix, rows, cols, i+1, j, maxi, dp);

    if(matrix[i][j] == 1){
        dp[i][j] = 1 + min(right, min(diagonal, down));
        maxi = max(dp[i][j], maxi);
        return dp[i][j];
    }
    else{
        return dp[i][j] = 0;
    }
};

int solveBottomUp(vector<vector<int>> &matrix, int &rows, int &cols){
    vector<vector<int>> dp(rows+1, vector<int> (cols+1, 0));
    int maxi = 0;

    for(int i=rows-1; i>=0; i--){
        for(int j=cols-1; j>=0; j--){

            int right = dp[i][j+1];
            int diagonal = dp[i+1][j+1];
            int down = dp[i+1][j];

            if(matrix[i][j] == 1){
                dp[i][j] = 1 + min(right, min(diagonal, down));
                maxi = max(dp[i][j], maxi);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    return maxi;
}

int solveSpaceOptimized(vector<vector<int>> &matrix, int &rows, int &cols){
    vector<int> curr(cols+1, 0);
    vector<int> next(cols+1, 0);

    int maxi = 0;

    for(int i=rows-1; i>=0; i--){
        for(int j=cols-1; j>=0; j--){

            int right = curr[j+1];
            int diagonal = next[j+1];
            int down = next[j];

            if(matrix[i][j] == 1){
                curr[j] = 1 + min(right, min(diagonal, down));
                maxi = max(curr[j], maxi);
            }
            else{
                curr[j] = 0;
            }
        }
        next = curr;
    }

    return maxi;
}

int solveMoreSpaceOptimized(vector<vector<int>> &matrix, int &rows, int &cols){
    int maxi = 0;

    for(int i=rows-1; i>=0; i--){
        for(int j=cols-1; j>=0; j--){

            int right = (j+1 >= cols)? 0 : matrix[i][j+1];
            int diagonal = (i+1 >= rows || j+1 >= cols)? 0 : matrix[i+1][j+1];
            int down = (i+1 >= rows)? 0 : matrix[i+1][j];

            if(matrix[i][j] == 1){
                matrix[i][j] = 1 + min(right, min(diagonal, down));
                maxi = max(matrix[i][j], maxi);
            }
        }
    }

    return maxi;
}

int main()
{
    int rows, cols;
    cout<<"Enter the size of matrix first row and then column with space in between"<<endl;
    cin>>rows>>cols; // 4 4.

    vector<vector<int>> matrix(rows, vector<int> (cols));
    cout<<"Enter the values of he matrix row wise"<<endl;
/* Test Case Start
1 0 1 0
0 1 1 1
0 1 1 1
1 1 0 0
Test Case End.*/
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin>>matrix[i][j];
        }
    }

    // Recursive Approach.
    // int maxi = 0;
    // int i = 0, j = 0;
    // solveRecursively(matrix, rows, cols, i, j, maxi);

    // Top Down Approach.
    // int maxi = 0;
    // int i = 0, j = 0;
    // vector<vector<int>> dp(rows, vector<int> (cols, -1));
    // solveTopDownMemo(matrix, rows, cols, i, j, maxi, dp);

    // Bottom Up Approach.
    //int maxi = solveBottomUp(matrix, rows, cols);

    // Space Optimized Approach.
    // int maxi = solveSpaceOptimized(matrix, rows, cols);

    // More Space Optimized Approach.
    int maxi = solveMoreSpaceOptimized(matrix, rows, cols);

    cout<<"Maximum size of submatrix of ones is : "<<maxi<<endl; // 2.

    return 0;
}