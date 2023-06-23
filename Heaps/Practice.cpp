#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

    TreeNode(int val){
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

TreeNode* buildBST(TreeNode* root, int val){
    if(root == nullptr){
        root = new TreeNode(val);
        return root;
    }

    if(root->data > val){
        root->left = buildBST(root->left, val);
    }
    else{
        root->right = buildBST(root->right, val);
    }

    return root;
}

void takingInput(TreeNode* &root){
    int data;
    cout<<"Enter the value of root node"<<endl;
    cin>>data;

    while(data != -1){
        root = buildBST(root, data);
        cin>>data;
    }
}

void inorderTraversal(TreeNode* root, vector<int> &ans){
    // Base Case.
    if(root == nullptr){
        return;
    }

    inorderTraversal(root->left, ans);
    ans.push_back(root->data);
    inorderTraversal(root->right, ans);
}

void heapify(TreeNode* &root, vector<int> &ans, int &index){
    //Base Case.
    if(root == nullptr){
        return;
    }

    root->data = ans[index++];

    heapify(root->left, ans, index);
    heapify(root->right, ans, index);
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
    //4 2 1 3 6 5 7 -1.
    takingInput(root);

    vector<int> ans;
    inorderTraversal(root, ans);

    int index = 0;
    heapify(root, ans, index);

    lvlOrderTraversal(root);

    return 0;
}