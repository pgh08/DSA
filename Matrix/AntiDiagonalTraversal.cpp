// Given a square matrix find the anti diagonal traversal.
// Example : 
/* Input : 3 2 3
           4 5 1
           7 8 9

   Output : 3 2 4 3 5 7 1 8 9.
*/
// Time Complexity : O(n^2), Space Complexity : O(n^2).
#include<iostream>
#include<vector>
using namespace std;

void getAntiDiagonalTraversal(vector<vector<int>> &matrix, int &n, vector<int> &ans){
    // Step 1 : Find the Upper Triangular matrix.
    /* For the above example it is :
        3 2 3
        4 5
        7
    */
    int row = 0;
    int col = 0;

    while(col < n){
        int j = col;
        int i = row;

        while(i < n && j >= 0){
            ans.push_back(matrix[i++][j--]);
        }
        col++;
    }

    // Step 2 : Find the Lower Triangular matrix.
    /* For the above example it is :
        - - -
        - - 1
        - 8 9
    */
    row = 1;
    col = n-1;

    while(row < n){
        int j = col;
        int i = row;

        while(i < n && j >= 0){
            ans.push_back(matrix[i++][j--]);
        }
        row++;
    }
}

int main()
{
    int n;
    cout<<"Enter the size of the matrix"<<endl;
    cin>>n;

    cout<<"Enter the elements of the matrix"<<endl;
    vector<vector<int>> matrix(n, vector<int> (n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>matrix[i][j];
        }
    }

    vector<int> ans;
    getAntiDiagonalTraversal(matrix, n, ans);

    // Printing ans.
    for(int i=0; i<n*n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}