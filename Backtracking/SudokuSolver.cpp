//Given a 9X9 vector of sudoku fill the empty fields in the sudoku.
/*
Algorithm :
    1. Using recursion and Backtracking :
        --> We must use 2 loops for traversing through the matrix.
        --> Another loop is used for inserting values from 1 to 9 and see whether that forms a valid sudoku.
        --> Before each insertion check whether the given place in the matrix is empty and safe.
        --> Safe condition is defined using following condition :
            i. Check whether the particular row of the matrix has that number. Row value remains same but column value changes.
            ii. Check whether the particular column of the matrix has that number. Column value remains same but row value changes.
            iii. Check whether the particular 3x3 matrix has that number. Use the formula : row = 3*(row/3) + i/3 and col = 3*(col/3) + i%3. Where i is the iterator of the loop.
        --> Use recursion to solve rest of the sudoku.
        --> If valid sudoku is not formable use backtracking to redo the steps followed uptill now.
        --> Time Complexity : O(9^m) where 'm' is the number of empty cells, Space complexity : O(9*9) = O(1).
*/
#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &sudoku, int value, int n){
    for(int i=0; i<n; i++){
        //Check for row elements.
        if(sudoku[row][i] == value){
            return false;
        }
        //Check for column elements.
        if(sudoku[i][col] == value){
            return false;
        }
        //Check for 3x3 matrix.
        if(sudoku[3*(row/3)+i/3][3*(col/3)+i%3] == value){
            return false;
        }
    }
    return true;
}

bool findSudoku(vector<vector<int>> &sudoku, int n){
    //Loops for traversing the matrix.
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            
            //Check whether particular place in the matrix is empty.
            if(sudoku[row][col] == 0){
                //Loop of inserting the value and checking for possible solution.
                for(int value=1; value<=9; value++){
                    //Check for safe place.
                    if(isSafe(row, col, sudoku, value, n)){
                        sudoku[row][col] = value;

                        //Check whether a possible outcome can come.
                        bool isPossible = findSudoku(sudoku, n);

                        if(isPossible){
                            return true;
                        }
                        else{
                            sudoku[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n;
    cout<<"Enter the dimention of the matrix"<<endl;
    cin>>n;

    //Constructing the sudoku.
    /* {3, 0, 6, 5, 0, 8, 4, 0, 0},
    {5, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 7, 0, 0, 0, 0, 3, 1},
    {0, 0, 3, 0, 1, 0, 0, 8, 0},
    {9, 0, 0, 8, 6, 3, 0, 0, 5},
    {0, 5, 0, 0, 9, 0, 6, 0, 0},
    {1, 3, 0, 0, 0, 0, 2, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 4},
    {0, 0, 5, 2, 0, 6, 3, 0, 0} */
    vector<vector<int>> sudoku(n, vector<int> (n,0));

    cout<<"Enter the values of the sudoku"<<endl;
    for(int row=0; row<n; row++){
        cout<<"Enter the values of "<<(row+1)<<"th row"<<endl;
        for(int col=0; col<n; col++){
            cin>>sudoku[row][col];
        }
    }
    cout<<endl;
    findSudoku(sudoku, n);
        //Printing the sudoku.
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<sudoku[i][j]<<" ";
            }
            cout<<endl;
        }

    return 0;
}