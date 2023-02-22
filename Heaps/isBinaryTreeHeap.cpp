//Given a binary tree check whether it is heap.
/*
Algorithm : 
    Step 1 : Check whether the given tree is both complete binary tree(CBT) and follows heap order property. If both case satisfy then binary tree is a heap.
    Step 2 : To check CBT use left child = 2*i+1 and right child = 2*i+2, if either of its value greater than the number of nodes in the tree then return false.
    Step 3 : To check if the tree follows heap order(should be CBT before hand), there are 3 conditions :- 
             1. Both child exists : In this case make sure both child value is smaller than the parent.
             2. Only left child exists : In this case make sure left child value is smaller than the parent.
             3. Leaf node : In this case return true regardless of the value.
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

    //Recursive call.
    cout<<"Enter the data for left side of "<<root->data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for right side of "<<root->data<<endl;
    root->right = buildTree(root->right);

    return root;
}

int countNodes(TreeNode* root){
    //Base case.
    if(root == nullptr){
        return 0;
    }
    int ans = 1 + countNodes(root->left) + countNodes(root->right);
    return ans;
}

bool isCBT(TreeNode* root, int index, int nodeCount){
    //Base case.
    if(root == nullptr){
        return true;
    }
    if(index >= nodeCount){
        return false;
    }

    //Recursive call.
    bool left = isCBT(root->left, 2*index+1, nodeCount);
    bool right = isCBT(root->right, 2*index+2, nodeCount);

    return left && right;
}

bool isMaxOrder(TreeNode* root){
    //Base case.
    if(root->left == nullptr && root->right == nullptr){
        return true;
    }
    if(root->left != nullptr && root->right == nullptr){
        return (root->data > root->left->data);
    }
    else{
        //Recursive call.
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return (left && right && (root->data > root->left->data && root->data > root->right->data));
    }
}
 

int main()
{
    TreeNode* root = nullptr;
    //10 5 1 -1 -1 2 -1 -1 9 -1 8 -1 -1.
    root = buildTree(root);

    int index = 0;
    int nodeCount = countNodes(root);

    if(isCBT(root, index, nodeCount) && isMaxOrder(root)){
        cout<<"The given Binary Tree is a Heap"<<endl;
    }
    else{
        cout<<"The given Binary Tree is not a Heap"<<endl;
    }

    return 0;
}