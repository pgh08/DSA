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
    int val;
    cout<<"Enter the data"<<endl;
    cin>>val;
    root = new TreeNode(val);

    if(val == -1){
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
        TreeNode* front = q.front();
        q.pop();

        if(front == nullptr){
            cout<<endl;

            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
            cout<<front->data<<" ";

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
    // 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1.
    root = buildTree(root);

    lvlOrderTraversal(root);

    return 0;
}