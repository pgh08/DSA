#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElements(vector<int> arr, int n){
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

vector<int> prevSmallerElements(vector<int> arr, int n){
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

int main()
{
    //Brute Force approach.
    /* int heights[6] = {2,1,5,6,2,3};
    int area = 0;
    for(int i=0; i<6; i++){
        int left = i;
        int right = i;
        int count = 1;
        //Checking left side.
        while(left > 0){
            if(heights[i] > heights[left-1]){
                break;
            }
            count++;
            left--;
        }
        //Checking right side.
        while(right < 5){
            if(heights[i] > heights[right+1]){
                break;
            }
            count++;
            right++;
        }
        area = max(area, count*heights[i]);
    }
    cout<<area<<endl; */

    int n;
    cout<<"Enter the size of array"<<endl;
    cin>>n;

    cout<<"Enter the heights"<<endl;
    vector<int> heights(n);
    for(int i=0; i<n; i++){
        cin>>heights[i];
    }

    vector<int> next(n);
    next = nextSmallerElements(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElements(heights, n);

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
    cout<<"Max area is : "<<area<<endl;

    return 0;
}