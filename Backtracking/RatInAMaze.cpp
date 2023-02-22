//Given a 2D vector name maze find the paths by which a Rat can reach destination(n-1,n-1) from source(0,0), path should be in sorted order.
/* 
Algorithm :
    1. Using recursion and Backtracking : 
        --> There are 3 conditions to be satisfied before Rat travels : 
            i. maze[i][j] must be 1.
            ii. visited[i][j] must be false.
            iii. i and j must be less then size of the matrix.
        --> Travel the maze in the order of (Sorted)(D,L,R,U) i.e. (Sorted)(Down,Left,Right,Up) respectively so that we can avoid sorting the ans vector at the end.
        --> Time Complexity : O(4^(n^2)), Space Complexity : O(n*m).
*/
#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int newX, int newY, vector<vector<int>> &maze, vector<vector<bool>> &visited, int n){
    if((newX >= 0 && newX < n) && (newY >= 0 && newY < n) && (maze[newX][newY] == 1) && (visited[newX][newY] == false)){
        return true;
    }
    return false;
}

void solveMaze(int x, int y, vector<vector<int>> maze, int n, string path, vector<string> &ans, vector<vector<bool>> &visited){
    //Base case.
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }
    visited[x][y] = true;
    //First movement.
    //Down. For Down movement 'x' co-ordinate varies and 'y' co-ordinate remains the same.
    if(isSafe(x+1, y, maze, visited, n)){
        solveMaze(x+1, y, maze, n, path + 'D', ans, visited);        
    }

    //Second movement.
    //Left. For Down movement 'x' co-ordinate remains the same and 'y' co-ordinate varies.
    if(isSafe(x, y-1, maze, visited, n)){
        solveMaze(x, y-1, maze, n, path + 'L', ans, visited); 
    }

    //Third movement.
    //Right. For Down movement 'x' co-ordinate remains the same and 'y' co-ordinate varies.
    if(isSafe(x, y+1, maze, visited, n)){
        solveMaze(x, y+1, maze, n, path + 'R', ans, visited); 
    }

    //Fourth movement.
    //Up. For Down movement 'x' co-ordinate varies and 'y' co-ordinate remains the same.
    if(isSafe(x-1, y, maze, visited, n)){
        solveMaze(x-1, y, maze, n, path + 'U', ans, visited); 
    }
    visited[x][y] = false;
}

int main()
{
    int n;
    cout<<"Enter the size of the maze"<<endl;
    cin>>n;

    vector<vector<int>> maze(n, vector<int> (n,0));

    cout<<"Enter the values of the maze"<<endl;
    for(int i=0; i<n; i++){
        cout<<"Enter the value of "<<(i+1)<<"th row"<<endl;
        for(int j=0; j<n; j++){
            cin>>maze[i][j];
        }
    }

    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool> (n,false));
    string path = "";
    int x = 0, y = 0;

    //Edge case.
    if(maze[x][y] == 0){
        cout<<"Rat cannot cross maze"<<endl;
    }

    solveMaze(x, y, maze, n, path, ans, visited);

    cout<<"Rat can cross the maze using following paths"<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    cout<<endl;

    return 0;
}