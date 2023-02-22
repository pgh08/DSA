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
    cout<<"Enter the for the left TreeNode of : "<<root->data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the for the right TreeNode of : "<<root->data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void lvlOrderTraversal(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
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

bool identical(TreeNode* root1, TreeNode* root2){
    //Base case.
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 != NULL && root2 == NULL){
        return false;
    }
    if(root1 == NULL && root2 != NULL){
        return false;
    }

    bool left = identical(root1->left, root2->left);
    bool right = identical(root1->right, root2->right);

    bool value = root1->data == root2->data;

    if(left && right && value){
        return true;
    }
    return false;
}

int main()
{
    TreeNode* root = NULL;
    // Tree : 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1.
    root = buildTree(root);

    lvlOrderTraversal(root);
    TreeNode* root1;
    TreeNode* root2;
    root1 = root2 = root;
    if(identical(root1, root2)){
        cout<<"Both trees are identical"<<endl;
    }
    else{
        cout<<"Both trees are not identical"<<endl;
    }

    return 0;
}