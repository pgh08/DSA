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

TreeNode* buildBST(TreeNode* root, int d){
    if(root == nullptr){
        root = new TreeNode(d);
        return root;
    }
    if(root->data > d){
        root->left = buildBST(root->left, d);
    }
    else{
        root->right = buildBST(root->right, d);
    }
    return root;
}

void takingInput(TreeNode* &root){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;

    while(data != -1){
        root = buildBST(root, data);
        cin>>data;
    }
}

TreeNode* LCA(TreeNode* root, int p, int q){
    if(root == nullptr){
        return root;
    }
    if(root->data > p && root->data > q){
        return LCA(root->left, p, q);
    }
    if(root->data < p && root->data < q){
        return LCA(root->right, p, q);
    }
    return root;
}

int main()
{
    TreeNode* root = nullptr;
    //6 2 8 0 4 7 9 3 5 -1.
    takingInput(root);

    int p = 2, q = 8;

    TreeNode* ans = LCA(root, p, q);

    cout<<"Lowest common ansister is : "<<ans->data<<endl;

    return 0;
}