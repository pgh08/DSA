//Given a binary tree print all the TreeNodes which are externally visible i.e. to print all the boundary elements.
/* 
Algorithm : 
    1. Print all the left boundary nodes except leaf nodes.
    2. Print all the left side leaf nodes.
    3. Print all the right side leaf nodes.
    4. Print all the right boundary nodes except leaf nodes.
*/
#include<iostream>
#include<vector>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

    TreeNode(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

    ~TreeNode(){}
};

TreeNode* buildTree(TreeNode* root){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    root = new TreeNode(data);

    if(data == -1){
        return NULL;
    }
    cout<<"Enter the data for left TreeNode of "<<root->data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for right TreeNode of "<<root->data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void leftPart(TreeNode* root, vector<int> &ans){
    if((root == NULL) || (root->left == NULL && root->right == NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->left){
        leftPart(root->left, ans);
    }
    else{
        leftPart(root->right, ans);
    }
}

void traverseLeaf(TreeNode* root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void rightPart(TreeNode* root, vector<int> &ans){
    if((root == NULL) || (root->left == NULL && root->right == NULL)){
        return;
    }
    if(root->right){
        rightPart(root->right, ans);
    }
    else{
        rightPart(root->left, ans);
    }

    ans.push_back(root->data);
}

int main()
{
    TreeNode* root = NULL;
    //1 2 3 -1 -1 5 6 -1 -1 8 -1 -1 4 -1 7 -1 9 10 -1 -1 11 -1 -1.
    root = buildTree(root);
    vector<int> ans;
    ans.push_back(root->data);
    //Printing left part.
    leftPart(root->left, ans);
    
    //Printing leaf TreeNodes.
    traverseLeaf(root->left, ans);//Left part leaf TreeNode.
    traverseLeaf(root->right,ans);//Right part leaf TreeNode.

    //Printing right part.
    rightPart(root->right, ans);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}