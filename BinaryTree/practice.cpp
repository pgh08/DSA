#include<iostream>
#include<limits.h>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

    TreeNode(int d){
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }

    ~TreeNode(){}
};

TreeNode* buildTree(TreeNode* root){
    int value;
    cout<<"Enter the data"<<endl;
    cin>>value;
    root = new TreeNode(value);

    if(value == -1){
        return nullptr;
    }

    cout<<"Enter the data for the left of "<<root->data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for the right of "<<root->data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void getMaxLenSum(TreeNode* root, int &sum, int len, int &maxLen, int &maxSum){
    // Base Case.
    if(root == nullptr){
        if(len > maxLen){
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen){
            maxSum = max(sum, maxSum);
        }
        return;
    }

    sum += root->data;

    getMaxLenSum(root->left, sum, len+1, maxLen, maxSum);
    getMaxLenSum(root->right, sum, len+1, maxLen, maxSum);
}

int main()
{
    TreeNode* root = nullptr;
    // 
    root = buildTree(root);

    int sum = 0;
    int len = 0;
    int maxLen = 0;
    int maxSum = INT_MIN;

    getMaxLenSum(root, sum, len, maxLen, maxSum);

    cout<<"Maximum lenght brach sum of a Tree is : "<<maxSum<<endl;

    return 0;
}