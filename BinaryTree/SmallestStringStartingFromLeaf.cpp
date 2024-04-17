// Given the root of the binary tree with numbers from [0, 25] representing english letters from 'a' to 'z'.
// Print lexicographically smallest string that starts at leaf and ends at root.
/* Approach : 1. Use temporary variable to store the string from leaf to root.
              2. When we come across leaf node compare it with ans and update the ans if ans is greater than temp.
              3. Time Complexity : O(n), Space Complexity : O(height of the tree).
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

void smallestFromLeaf(TreeNode* root, string &ans, string temp){
    // Base Case.
    if(!root){
        return;
    }

    if(!root->left && !root->right){
        temp = char(root->val+'a') + temp;
        if(ans == "" || ans > temp){
            ans = temp;
        }
        return;
    }

    smallestFromLeaf(root->left, ans, (char(root->val+'a') + temp));
    smallestFromLeaf(root->right, ans, (char(root->val+'a') + temp));
}

int main()
{
    TreeNode* root = nullptr;
    root = buildTree(root); // 0 1 3 -1 -1 4 -1 -1 2 3 -1 -1 4 -1 -1.

    string ans = "";
    string temp = "";

    smallestFromLeaf(root, ans, temp);

    cout<<"Smallest string formed is : "<<ans<<endl; // dba.

    return 0;
}