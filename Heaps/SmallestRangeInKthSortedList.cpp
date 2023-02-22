//Given an array of 'K' vectors find the least range which include atleast one element of all the vectors.
/*
Algorithm : 
    1. Brute force : 
        -->Get all the ranges using 3 for loops and keep track of minimum.
        -->Time complexity : O(n^2*k^2), Space complexity : O(n*k).

    2. Using seperate data structure(keep a class) :
        -->Make an array in class which consists of all the first elements of all the array from input.
        -->Make min and max data members in class and keep updating them. We can reduce range in two ways one by increasing min value of current range and second one is by decreasing
           max value of the cuurent range but second option is not possible because given arrays are sorted in increasing order.
        -->Time complexity : O(n*k^2), Space complexity : O(k).

    3. Using MinHeap :
        -->Make a min heap and put all the starting element of the arrays in minHeap and keep track of min and max while inserting.
        -->Keep start and end variable to getting difference.
        -->Run a loop till minHeap's size not become null keep updating minvalue and update range when max-min < end - start.
        -->If array of that particular row's column+1 is less than size the update max and push element,row and column in minHeap.
        -->Time complexity : O(n*log(K)), Space complexity : O(k).
*/
#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>
using namespace std;

class node{
    public:
        int data;
        int rowIndex;
        int colIndex;

    node(int d, int row, int col){
        this->data = d;
        this->rowIndex = row;
        this->colIndex = col;
    }
};

class comapre{
    public:
        bool operator()(node* a, node* b){
            return a->data > b->data;
        }
};

pair<int,int> samllestRange(vector<vector<int>> &nums, int n){
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<node*, vector<node*>, comapre> minHeap;

    for(int i=0; i<n; i++){
        int element = nums[i][0];
        maxi = max(maxi,element);
        mini = min(mini,element);
        minHeap.push(new node(element, i, 0));
    }

    int start = mini, end = maxi;

    while(!minHeap.empty()){
        node* top = minHeap.top();
        minHeap.pop();

        mini = top->data;
        int size = nums[top->rowIndex].size();

        if((maxi-mini) < (end-start)){
            start = mini;
            end = maxi;
        }

        if(top->colIndex + 1 < size){
            maxi = max(maxi,nums[top->rowIndex][top->colIndex+1]);
            minHeap.push(new node(nums[top->rowIndex][top->colIndex+1], top->rowIndex, top->colIndex+1));
        }
        else{
            break;
        }
    }
    return {start, end};
}

int main()
{   
    int n;
    cout<<"Enter the number of rows"<<endl;
    cin>>n;
    vector<vector<int>> nums(n);

    for(int i=0; i<n; i++){
        int k;
        cout<<"Enter the number of columns"<<endl;
        cin>>k;

        nums[i] = vector<int>(k);

        cout<<"Enter the data for "<<i+1<<"th array"<<endl;

        for(int j=0; j<k; j++){
            cout<<"Enter the data"<<endl;
            cin>>nums[i][j];
        }
    }

    cout<<endl;
    pair<int,int> ans = samllestRange(nums, n);
    int length = ans.second - ans.first + 1;

    cout<<"Minimum range is : ["<<ans.first<<","<<ans.second<<"] with length "<<length<<endl;

    return 0;
}