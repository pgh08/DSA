// Given a binary tree's root node, value of node to be added and depth, add TreeNode of value (val) at depth (depth) in a tree.
// If depth is 1 then create new root node and link current root node to left of the new root.
#include<iostream>
#include<queue>
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

TreeNode* addRow(TreeNode* root, int val, int depth){
    if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

    queue<pair<TreeNode*,int>> q;
    q.push({root, 1});

    while(!q.empty()){
        auto front = q.front();
        q.pop();

        if(front.second+1 == depth){
            TreeNode* nodeToInsertLeft = new TreeNode(val);
            TreeNode* nodeToInsertRight = new TreeNode(val);
            nodeToInsertLeft->left = front.first->left;
            nodeToInsertRight->right = front.first->right;
            front.first->left = nodeToInsertLeft;
            front.first->right = nodeToInsertRight;         
        }

        if(front.first->left){
            q.push({front.first->left, front.second+1});
        }
        if(front.first->right){
            q.push({front.first->right, front.second+1});
        }
    }

    return root;
}

void lvlOrderTraversal(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        TreeNode* front = q.front();
        q.pop();

        if(front == NULL){
            cout<<endl;

            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<front->val<<" ";
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
    }
}

int main()
{
    TreeNode* root = nullptr;
    root = buildTree(root); // 4 2 3 -1 -1 1 -1 -1 6 5 -1 -1 -1.

    int val, depth;
    cout<<"Enter the value val of node to be inserted and depth at which it is to be inserted"<<endl;
    cin>>val>>depth;

    TreeNode* ans = addRow(root, val, depth);

    cout<<"Final Tree is : "<<endl;
    lvlOrderTraversal(root); // 4 1 1 2 6 3 1 5.

    return 0;
}