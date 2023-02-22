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
};

TreeNode* buildBST(TreeNode* root, int data){
    if(root == nullptr){
        root = new TreeNode(data);
        return root;
    }
    if(root->data > data){
        root->left = buildBST(root->left, data);
    }
    else{
        root->right = buildBST(root->right, data);
    }
    return root;
}

void buildTree(TreeNode* &root){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;

    while(data != -1){
        root = buildBST(root, data);
        cin>>data;
    }
}

void Inorder(TreeNode* root){
    if(root == nullptr){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

int main()
{
    TreeNode* root = nullptr;
    //10 43 23 1 3 2 -1.
    buildTree(root);

    Inorder(root);
    cout<<endl;

    return 0;
}