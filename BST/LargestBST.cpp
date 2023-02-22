//Given a Binary Tree return maximum number of nodes which form a BST.
/* 
Algorithm:
1. Brute force :
    -->Visit every node and check whether it makes a valid BST.
    -->Time complexcity : O(n^2), Space complexcity : O(n).

2. Optimized :
    -->By creating a class consisting of 4 different informations.
    -->Information are : (int)max, (int)min, (bool)isBST, (int)size.
    -->Processing each node only once and checking left sudtree is a valid BST and right subtree is a valid BST and max(left) < root->data < min(right).
    -->Time complexcity : O(n) Space complexcity : O(n).
*/

#include<iostream>
#include<limits.h>
#include<vector>
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

class info{
    public:
        int mini;
        int maxi;
        bool isBST;
        int size;
};

TreeNode* buildTree(TreeNode* root){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    root = new TreeNode(data);

    if(data == -1){
        return nullptr;
    }
    cout<<"Enter the data for left of : "<<root->data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for right of : "<<root->data<<endl;
    root->right = buildTree(root->right);

    return root;
}

info solve(TreeNode* root, int &maxSize){
    //Base case.
    if(root == nullptr){
        return {INT_MAX, INT_MIN, true, 0};
    }

    info left = solve(root->left, maxSize);
    info right = solve(root->right, maxSize);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
        currNode.isBST = true;
    }
    else{
        currNode.isBST = false;
    }
    //Answer update.
    if(currNode.isBST){
        maxSize = max(maxSize, currNode.size);
    }
    return currNode;
}

int largestBST(TreeNode* root){
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}

int main()
{
    TreeNode* root = nullptr;
    //5 2 1 -1 -1 3 -1 -1 4 -1 -1.
    root = buildTree(root);

    int ans = largestBST(root);

    cout<<"Size of a largest BST is : "<<ans<<endl;

    return 0;
}