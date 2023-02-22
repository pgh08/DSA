//Given 'K' sorted arrays merge them and find resultant array which is sorted.
/*
Algorithm :
    1. Brute force :
        -->Push all the elements into newly created array. Time complexity : O(n*k), Space complexity : O(n*k).
        -->Sort the above array. So the overall Time complexity : O((n*k)log(n*k)), Space complexity : O(n*k).
    
    2. Using MinHeap : 
        -->Push all the first elements of the array to minHeap because all the arrays are sorted.
        -->Now top element has smallest value so push that into the ans array and if another element is present in that array push it to minHeap.
        -->Time complexity : O((n*k)log(k)), Space complexity : O(n*k).
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class node{
    public:
        int data;
        int row;
        int col;

    node(int d, int rowIndex, int colIndex){
        this->data = d;
        this->row = rowIndex;
        this->col = colIndex;
    }
};

class compare{
    public:
        bool operator()(node* a, node* b){
            return a->data > b->data;
        }
};

void sortKArrays(int *arr[], int k, vector<int> &ans, int *num){
    priority_queue<node*, vector<node*>, compare> minHeap;

    //Step 1 :
    for(int i=0; i<k; i++){
        node* temp = new node(arr[i][0], i, 0);
        minHeap.push(temp);
    }

    //Step 2 :
    while(minHeap.size() > 0){
        node* eachColSmallest = minHeap.top();

        ans.push_back(eachColSmallest->data);
        minHeap.pop();

        int row = eachColSmallest->row;
        int col = eachColSmallest->col;
        int rowSize = num[row];
        
        if(col+1 < rowSize){
            node* next = new node(arr[row][col+1], row, col+1);
            minHeap.push(next);
        }
    }
}

int main()
{
    int k;
    cout<<"Enter the number of arrays"<<endl;
    cin>>k;

    int **arr = new int *[k];
    int *num = new int[k];

    for(int i=0; i<k; i++){
        cout<<"Enter the number of elements in "<<i+1<<"st array"<<endl;
        cin>>num[i];
        arr[i] = new int[num[i]];
    }

    for(int i=0; i<k; i++){
        for(int j=0; j<num[i]; j++){
            cout<<"Enter the elements of "<<i+1<<"st array"<<endl;
            cin>>arr[i][j];
        }
    }

    vector<int> ans;

    sortKArrays(arr, k, ans, num);

    int size = ans.size();

    //Printing sorted array.
    cout<<"Merged array is : "<<endl;
    for(int i=0; i<size; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}