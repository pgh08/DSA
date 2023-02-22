//Given a integer 'N' as input check different ways how Queen can be placed in a chess board of N x N so that no Queens attack each other.
/*
Algorithm :
    1. Using recursion and Bactracking : 
        --> Create a board of N x N with all zeros. Here zero's represent where queen is not placed and one's represent queen is placed.
        --> Check a particular place in board is safe for placing the queen, safe place is a place which satisfies : 
            i. Only 1 queen present in that row.
            ii. Only 1 queen present in that column (already taken care by our approach).
            iii. No queen attack each other.
        --> Queen's Direction of travel are Up, Down, Rowwise, Columnwise, Diagonal.
        --> In isSafe function check all the column elements left side of the place of Q is '0' else return false.
        --> For diagonal there is 2 possibilities :
            i. Upper diagonal. Both row and column decreases.
            ii. Lower diagonal. Row value increases, Column value decreases.
            In above 2 cases if board value is found to be 1 return false.
    2. Using recursion and Bactracking with map :
        --> In isSafe function to check a place is safe we consumed O(n) time complexity for all 3 conditions.
        --> Instead we can make 3 maps :
            i. Map 1 : To store row and bool value for checking first condition.
            ii. Map 2 (For lower diagonal): In this case map's key is (row+col) and value is bool. Same value of lower diagonal is formed in map's key.
            iii. Map 3 (For upper diagonal): In this case map's key is ((N-1)+(col-row)) and value is bool. Same value of upper diagonal is formed in map's key.
        --> For extra info refer notebook.
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n){
    vector<int> temp;
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            temp.push_back(board[row][col]);
        }
    }
    ans.push_back(temp);
}
//First approach.
/* bool isSafe(int row, int col, vector<vector<int>> &board, int n){
    int x = row;
    int y = col;

    //For checking row.
    while(y >= 0){
        if(board[x][y] == 1){
            return false;
        }
        y--;
    }

    x = row, y = col;
    //For checking lower diagonal.
    while(x >= 0 && y >= 0){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }

    x = row, y = col;
    //For checking upper diagonal.
    while(x < n && y >= 0){
        if(board[x][y] == 1){
            return false;
        }
        x++;
        y--;
    }
    return true;
}

void NQueenWays(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n){
    if(col == n){
        //To add a possible way to ans.
        addSolution(board, ans, n);
        return;
    }
    //Since we are already considering column only vary row value.
    for(int row=0; row<n; row++){
        if(isSafe(row, col, board, n)){
            board[row][col] = 1;
            NQueenWays(col+1, board, ans, n);
            //Backtracking.
            board[row][col] = 0;
        }
    }
} */

bool isSafe(int row, int col, vector<vector<int>> &board, int n, unordered_map<int,bool> &rowToQueen, unordered_map<int,bool> &lowerDiagonalToQueen, unordered_map<int,bool> &upperDiagonalToQueen){
    //For checking row, Lower diagonal and Upper diagonal.
    if((rowToQueen[row] == false) && (lowerDiagonalToQueen[row+col] == false) && (upperDiagonalToQueen[(n-1)+(col-row)] == false)){
        return true;
    }
    return false;
}

void NQueenWays(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n, 
                    unordered_map<int,bool> &rowToQueen, unordered_map<int,bool> &lowerDiagonalToQueen, unordered_map<int,bool> &upperDiagonalToQueen){
    if(col == n){
        //To add a possible way to ans.
        addSolution(board, ans, n);
        return;
    }
    //Since we are already considering column only vary row value.
    for(int row=0; row<n; row++){
        if(isSafe(row, col, board, n, rowToQueen, lowerDiagonalToQueen, upperDiagonalToQueen)){
            board[row][col] = 1;
            rowToQueen[row] = true;
            lowerDiagonalToQueen[row+col] = true;
            upperDiagonalToQueen[(n-1)+(col-row)] = true;
            NQueenWays(col+1, board, ans, n,  rowToQueen, lowerDiagonalToQueen, upperDiagonalToQueen);
            //Backtracking.
            board[row][col] = 0;
            rowToQueen[row] = false;
            lowerDiagonalToQueen[row+col] = false;
            upperDiagonalToQueen[(n-1)+(col-row)] = false;
        }
    }
}

void createMapping(vector<vector<int>> &board, int n,  unordered_map<int,bool> &rowToQueen, unordered_map<int,bool> &lowerDiagonalToQueen, unordered_map<int,bool> &upperDiagonalToQueen){
    for(int row=0; row<n; row++){
        rowToQueen[row] = false;
        for(int col=0; col<n; col++){
            lowerDiagonalToQueen[row+col] = false;
            upperDiagonalToQueen[(n-1)+(col-row)] = false;
        }
    }
}

int main()
{
    int n;
    cout<<"Enter the number of Queen should be placed in N x N chess board"<<endl;
    cin>>n;

    //Constructing a board.
    vector<vector<int>> board(n, vector<int> (n,0));
    vector<vector<int>> ans;
    int col = 0;

    //First approach.
    //NQueenWays(col, board, ans, n);

    //Optimized approach.
    unordered_map<int,bool> rowToQueen, lowerDiagonalToQueen, upperDiagonalToQueen;

    createMapping(board, n, rowToQueen, lowerDiagonalToQueen, upperDiagonalToQueen);

    NQueenWays(col, board, ans, n, rowToQueen, lowerDiagonalToQueen, upperDiagonalToQueen);

    //Printing the values.
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            if(j%n == 0){
                cout<<endl;
            }
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
}