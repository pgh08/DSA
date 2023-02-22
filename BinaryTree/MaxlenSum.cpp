#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

    ~node(){}
};

node* buildTree(node* root){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for left of "<<root->data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for right of "<<root->data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void maxLenSum(node* root, int sum, int &maxSum, int len, int &maxLen){
    //Base case.
    if(root == NULL){
        if(len > maxLen){
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen){
            maxSum = max(sum, maxSum);
        }
        return;
    }

    sum = sum + root->data;
    maxLenSum(root->left, sum, maxSum, len+1, maxLen);
    maxLenSum(root->right, sum, maxSum, len+1, maxLen);
}

int main()
{
    node* root = NULL;
    //4 2 7 -1 -1 1 6 -1 -1 -1 5 2 -1 -1 3 -1 -1.
    root = buildTree(root);

    int maxLen = 0;
    int maxSum = INT_MIN;
    int sum = 0;
    int len = 0;

    maxLenSum(root, sum, maxSum, len, maxLen);

    cout<<"Maximum lenght is : "<<maxLen<<" with sum : "<<maxSum<<endl;

    return 0;
}