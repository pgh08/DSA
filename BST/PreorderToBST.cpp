#include<iostream>
#include<limits.h>
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

    ~TreeNode(){}
};
//Algorithm : Keeping the Range for each node.
TreeNode* buildFromPreorder(int preorder[], int minValue, int maxValue, int &index, int size){
    if(index >= size){
        return nullptr;
    }
    if(preorder[index] < minValue || preorder[index] > maxValue){
        return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[index++]);
    root->left = buildFromPreorder(preorder, minValue, root->data, index, size);
    root->right = buildFromPreorder(preorder, root->data, maxValue, index, size);

    return root;
}

void lvlOrderTraversal(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();

        if(temp == nullptr){
            cout<<endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
            cout<<temp->data<<" ";

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    TreeNode* root = NULL;
    int n = 8;
    int preorder[8] = {20,10,5,15,13,35,30,42};
    int minValue = INT_MIN;
    int maxValue = INT_MAX;
    int index = 0;

    root = buildFromPreorder(preorder, minValue, maxValue, index, n);

    lvlOrderTraversal(root);

    return 0;
}