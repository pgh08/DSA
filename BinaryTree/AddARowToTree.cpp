// Given the depth and the value of the node add a row in Binary Tree at given depth.
#include<iostream>
#include<queue>
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

TreeNode* buildTree(TreeNode* root){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    root = new TreeNode(data);

    if(data == -1){
        return nullptr;
    }

    cout<<"Enter the data for the left of "<<root->data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for the right of "<<root->data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void lvlOrderTraversal(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        TreeNode* frontNode = q.front();
        q.pop();

        if(frontNode == nullptr){
            cout<<endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
            cout<<frontNode->data;

            if(frontNode->left){
                q.push(frontNode->left);
            }

            if(frontNode->right){
                q.push(frontNode->right);
            }
        }
    }
    cout<<endl;
}

void addOneRow(TreeNode* &root, const int depth, const int value, int lvl){
    // Base Case.
    if(root == nullptr){
        return;
    }

    addOneRow(root->left, depth, value, lvl+1);
    addOneRow(root->right, depth, value, lvl+1);

    if(lvl == depth){
        TreeNode* leftPart = root->left;
        TreeNode* rightPart = root->right;

        root->left = new TreeNode(value);
        root->right = new TreeNode(value);

        root->left->left = leftPart;
        root->right->right = rightPart;
    }
}

int main()
{
    TreeNode* root = nullptr;
    // 4 2 3 -1 -1 1 -1 -1 6 5 -1 -1 -1.
    root = buildTree(root);

    lvlOrderTraversal(root);

    int depth;
    cout<<"Enter the depth where you want to insert a row"<<endl;
    cin>>depth;

    int value;
    cout<<"Enter the value of the node to be inserted"<<endl;
    cin>>value;

    if(depth == 1){
        TreeNode* newRoot = new TreeNode(value);
        newRoot->left = root;
        lvlOrderTraversal(newRoot);
        return 0;
    }

    int lvl = 1;
    addOneRow(root, depth, value, lvl);

    lvlOrderTraversal(root);

    return 0;
}