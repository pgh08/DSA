#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> arr, int n){
    stack<int> s1;
    s1.push(-1);
    vector<int> ans1(n);

    for(int i=n-1; i>=0; i--){
        int curr = arr[i];
        while(s1.top() != -1 && arr[s1.top()] >= curr){
            s1.pop();
        }
        ans1[i] = s1.top();
        s1.push(i);
    }
    return ans1;
}

vector<int> prevSmallerElement(vector<int> arr, int n){
    stack<int> s2;
    s2.push(-1);
    vector<int> ans2(n);

    for(int i=0; i<n; i++){
        int curr = arr[i];
        while(s2.top() != -1 && arr[s2.top()] >= curr){
            s2.pop();
        }
        ans2[i] = s2.top();
        s2.push(i);
    }
    return ans2;
}

int largestRectangularArea(vector<int> heights, int n){
    vector<int> next(n);
    next = nextSmallerElement(heights, n);
    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);

    int area = INT_MIN;
    for(int i=0; i<n; i++){
        int length = heights[i];
        if(next[i] == -1){
            next[i] = n;
        }
        int breadth = next[i]-prev[i]-1;
        int eachArea = length*breadth;
        area = max(area, eachArea);
    }
    return area;
}

int main()
{
    vector<vector<int>> M = {{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,0,0}};
    int n = M.size();
    int m = M[0].size();
    int area = largestRectangularArea(M[0], m);

    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            //Updating row by adding previous row values.
            if(M[i][j] != 0){
                M[i][j] = M[i][j] + M[i-1][j];
            }
            else{
                M[i][j] = 0;

            }
        }
        //Entire row is updated now.
        area = max(area, largestRectangularArea(M[i], m));
    }
    cout<<"Area is : "<<area<<endl;

    return 0;
}