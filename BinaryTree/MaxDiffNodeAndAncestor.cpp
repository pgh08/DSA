// Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b. A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.
// Time Complexity : O(n), Space Complexity : O(n).
#include<iostream>
#include<limits.h>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left; 
        TreeNode* right;

    TreeNode(int val){
        this->data = val;
        this->left = this->right = nullptr;
    }
};

TreeNode* buildTree(TreeNode* root){
    int val;
    cout<<"Enter the value of the node"<<endl;
    cin>>val;
    root = new TreeNode(val);

    if(val == -1){
        return nullptr;
    }

    cout<<"Enter the value for left of "<<root->data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the value for right of "<<root->data<<endl;
    root->right = buildTree(root->right);

    return root;
}

int maxAncestorDiff(TreeNode* root, int mini = INT_MAX, int maxi = INT_MIN){
    // Base Case.
    if(root == nullptr){
        return maxi-mini;
    }

    maxi = max(maxi, root->data);
    mini = min(mini, root->data);

    int left = maxAncestorDiff(root->left, mini, maxi);
    int right = maxAncestorDiff(root->right, mini, maxi);

    return max(left, right);
}

int main()
{
    TreeNode* root = nullptr;
    root = buildTree(root); // 8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1.

    // Keep track of maximum and minimum element in each node and at base case return max-min.
    int ans = maxAncestorDiff(root);

    cout<<"Maximum difference between the ancestor is : "<<ans<<endl; // 7.

    return 0;
}