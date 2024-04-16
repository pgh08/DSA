// Leetcode Problem : Given a binary tree representing the digits of a number, find the sum of all numbers which can be constructed 
//                    traversing from root to leaf.
/* Approach : 
             1. Keep Track of path and multiply it by 10 after each iteration.
             2. If leaf node is found then again multiply by 10 and add root's value.
             3. Add path value to the sum when the leaf node is found.
             4. Time Complexity : O(n), Space Complexity : O(height of the tree).
*/
#include<iostream>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode *left, *right;

    TreeNode(int data){
        this->val = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

TreeNode* buildTree(TreeNode* root){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    root = new TreeNode(data);

    if(data == -1){
        return nullptr;
    }

    cout<<"Enter the data for the left of "<<root->val<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for the right of "<<root->val<<endl;
    root->right = buildTree(root->right);

    return root;
}

void getSum(TreeNode* root, int &sum, int path){
    // Base Case.
    if(!root){
        return;
    }
    if(!root->left && !root->right){
        sum += path*10+root->val;
        return;
    }

    getSum(root->left, sum, (path*10+root->val));
    getSum(root->right, sum, (path*10+root->val));
}

int main()
{
    TreeNode* root = nullptr;
    root = buildTree(root); // 4 9 5 -1 -1 1 -1 -1 0 -1 -1.

    int sum = 0;
    int path = 0;

    getSum(root, sum, path);

    cout<<"Sum of all number which can be formed from traversing root to leaf is : "<<sum<<endl; // 1026.

    return 0;
}