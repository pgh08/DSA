//Given the Binary Tree find if it is a balanced tree or not.
/*
Algorithm : 
    1. Tree is said to be balanced if the height difference between of left and right subtree for each node is not more than one.
    2. Find the height difference between 2 subtree and check whethere it is less than or equal to 1.
*/
#include<iostream>
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
};

TreeNode* buildTree(TreeNode* root){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    root = new TreeNode(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for left of "<<root->data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for right of "<<root->data<<endl;
    root->right = buildTree(root->right);

    return root;
}

int height(TreeNode* root){
    //Base case.
    if(root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left, right) + 1;

    return ans;
}

pair<bool,int> balanceFast(TreeNode* root){
    //Base case.
    if(root == NULL){
        pair<bool,int> p = make_pair(1,0);
        return p;
    }

    pair<bool,int> left = balanceFast(root->left);
    pair<bool,int> right = balanceFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = abs(left.second - right.second) <= 1;

    pair<bool,int> ans;
    ans.second = max(left.second, right.second) + 1;

    if(leftAns && rightAns && diff){
        ans.first = true;
    }
    else{
        ans.first = false;
    }

    return ans;
}

bool balancedTree(TreeNode* root){
    return balanceFast(root).first;
    /* //Base case.
    if(root == NULL){
        return true;
    }

    bool left = balancedTree(root->left);
    bool right = balancedTree(root->right);
    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if(left && right && diff){
        return true;
    }
    else{
        return false;
    }*/
}

int main()
{
    TreeNode* root = NULL;
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1.
    root = buildTree(root);

    if(balancedTree(root)){
        cout<<"Tree is Balanced"<<endl;
    }
    else{
        cout<<"Tree is Not Balanced"<<endl;
    }
    return 0;
}