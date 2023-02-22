#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row;
    cout<<"Enter the number of rows"<<endl;
    cin>>row;

    int *num = new int[row];
    int **arr = new int *[row];

    for(int i=0; i<row; i++){
        cout<<"Enter the number of column in this array"<<endl;
        cin>>num[i];
        arr[i] = new int[num[i]];
    }
    //Taking Input.
    for(int i=0; i<row; i++){
        for(int j=0; j<num[i]; j++){
            cin>>arr[i][j];
        }
    }
    //Printing Output.
    for(int i=0; i<row; i++){
        for(int j=0; j<num[i]; j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    //Releasing memory.
    for(int i=0; i<row; i++){
        delete []arr[i];
    }
    delete []arr;
    delete []num;
    
    return 0;
}