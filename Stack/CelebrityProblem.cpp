#include<bits/stdc++.h>
using namespace std;

void twoPointer(vector<vector<int>> &M, int n){
    int i = 0, j = n-1;

    while(i < j){
        if(M[i][j] == 1){
            i++;
        }
        else{
            j--;
        }
    }
    int candidate = i;

    for(int i=0; i<n; i++){
        if(i != candidate){
            if(M[candidate][i] == 1 || M[i][candidate] == 0){
                candidate = -1;
                break;
            }
        }
    }

    if(candidate != -1){
        cout<<"Celebrity is : "<<candidate<<endl;
    }
}

bool knows(vector<vector<int>> M, int a, int b, int n){
    if(M[a][b] == 1){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    vector<vector<int>> M = {{0,1,0},{0,0,0},{0,1,0}};
    int n = M.size();
    stack<int> s;
    //Pushing 0, 1, 2 in stack.
    for(int i=0; i<n; i++){
        s.push(i);
    }

    //a knows b or b knows a approach.
    while(s.size() > 1){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if(knows(M, a, b, n)){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    //A possible solution.
    int ans = s.top();
    int zeroCount = 0, oneCount = 0;
    //Checking corresponding row for all zeros for a particular ans.
    for(int i=0; i<n; i++){
        if(M[ans][i] == 0){
            zeroCount++;
        }
    }
    //Checking corresponding column for all one except diagonal for a particular ans.
    for(int i=0; i<n; i++){
        if(M[i][ans] == 1){
            oneCount++;
        }
    }
    //Checking wether both conditions satisfies.
    if(zeroCount != n || oneCount != n-1){
        cout<<"No such celebrity"<<endl;
        return 0;
    }
    cout<<"Celebrity is : "<<ans<<endl;

    twoPointer(M, n);

    return 0;
}