#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<char>> &mat, int row, int col, vector<vector<int>> &visited, int *delRow, int *delCol, int &n, int &m){
    visited[row][col] = 1;
        
    for(int i=0; i<4; i++){
        int newRow = row + delRow[i];
        int newCol = col + delCol[i];
        
        if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !visited[newRow][newCol] && mat[newRow][newCol] == 'O'){
            dfs(mat, newRow, newCol, visited, delRow, delCol, n, m);
        }
    }
}

void fillTheMatrix(int &n, int &m, vector<vector<char>> &mat)
{
    // code here.
    vector<vector<int>> visited(n, vector<int> (m, 0));
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    
    // Traverse First and Last row.
    for(int i=0; i<m; i++){
        
        if(!visited[0][i] && mat[0][i] == 'O'){
            dfs(mat, 0, i, visited, delRow, delCol, n, m);
        }
        
        if(!visited[n-1][i] && mat[n-1][i] == 'O'){
            dfs(mat, n-1, i, visited, delRow, delCol, n, m);
        }
    }
    
    // Traverse First and Last column.
    for(int i=0; i<n; i++){
        
        if(!visited[i][0] && mat[i][0] == 'O'){
            dfs(mat, i, 0, visited, delRow, delCol, n, m);
        }
        
        if(!visited[i][m-1] && mat[i][m-1] == 'O'){
            dfs(mat, i, m-1, visited, delRow, delCol, n, m);
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && mat[i][j] == 'O'){
                mat[i][j] = 'X';
            }
        }
    }
}

int main()
{
    int n, m;
    cout<<"Enter the number of rows and columns in the matrix"<<endl;
    cin>>n>>m;

    vector<vector<char>> mat(n, vector<char> (m));
    cout<<"Enter the value of the matrix"<<endl;
    // {{'X', 'X', 'X', 'X'}, 
    // {'X', 'O', 'X', 'X'}, 
    // {'X', 'O', 'O', 'X'}, 
    // {'X', 'O', 'X', 'X'}, 
    // {'X', 'X', 'O', 'O'}}
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>mat[i][j];
        }
    }

    fillTheMatrix(n, m, mat);

    cout<<"The resultant matrix is : "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}