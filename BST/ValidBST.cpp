#include<iostream>
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
    int data;
    cin>>data;
    root = new TreeNode(data);

    if(data == -1){
        return nullptr;
    }

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

bool isValid(TreeNode* root, TreeNode* min, TreeNode* max){
    if(root == NULL){
        return true;
    }
    if((min != nullptr && root->data <= min->data) || (max != nullptr && root->data >= max->data)){
        return false;
    }
    return isValid(root->left, min, root) && isValid(root->right, root, max);
}

int main()
{
    TreeNode* root = NULL;
    //10 15 4 -1 -1 6 -1 -1 20 15 -1 -1 25 -1 -1.
    root = buildTree(root);
    //Approach 1 is to do inorder traversal storing TreeNode values in an array and checking where the resultant array is sorted.
    //Approach 2 is maintaining range for each TreeNode can checking whether next Treenode value lies within the range.
    //Maintain min and max TreeNode value for each node.
    TreeNode* min = nullptr;
    TreeNode* max = nullptr;

    if(isValid(root, min, max)){
        cout<<"Tree is valid BST"<<endl;
    }
    else{
        cout<<"Tree is not a valid BST"<<endl;
    }

    return 0;
}