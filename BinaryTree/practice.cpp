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
    cout<<"Enter the data"<<endl;
    cin>>data;
    root = new TreeNode(data);

    if(data == -1){
        return nullptr;
    }
    
    cout<<"Enter the data for left of "<<root->data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter the data for right of "<<root->data<<endl;
    root->right = buildTree(root->right);

    return root;
}

int getHeight(TreeNode* root){
    // Base Case.
    if(root == nullptr){
        return 0;
    }

    int left = getHeight(root->left);
    int right = getHeight(root->right);

    int ans = max(left,right) + 1;

    return ans;
}

int main()
{
    TreeNode* root = nullptr;
    // 1 2 3 4 -1 -1 -1 -1 5 -1 -1.
    root = buildTree(root);

    int height = getHeight(root);

    cout<<"Height of Tree is : "<<height<<endl;

    return 0;
}