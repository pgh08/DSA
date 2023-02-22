//Given a BST convert it into Min Heap.
/*
Algorithm : 
    1. Get Inorder from BST which is sorted.
    2. Change the value of BST using preorder traversal.
    3. Time complexity : O(n), Space complexity : O(n).
*/
#include<iostream>
#include<vector>
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

TreeNode* buildBST(TreeNode* root, int data){
    if(root == nullptr){
        root = new TreeNode(data);
        return root;
    }
    if(data < root->data){
        root->left = buildBST(root->left, data);
    }
    else{
        root->right = buildBST(root->right, data);
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

void inorderTraversal(TreeNode* root, vector<int> &ans){
    //Base case.
    if(root == nullptr){
        return;
    }
    //Recursive call.
    inorderTraversal(root->left, ans);
    ans.push_back(root->data);
    inorderTraversal(root->right, ans);
}

void changeValueFromPreorder(TreeNode* &root, vector<int> &ans, int &index){
    //Base case.
    if(root == nullptr){
        return;
    }
    //Recursive call.
    root->data = ans[index++];
    changeValueFromPreorder(root->left, ans, index);
    changeValueFromPreorder(root->right, ans, index);
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
    TreeNode* root = nullptr;
    //4 2 1 3 6 5 7 -1.
    takingInput(root);

    cout<<"Before Heapifing"<<endl;
    lvlOrderTraversal(root);

    //Step : 1
    vector<int> ans;
    inorderTraversal(root, ans);

    //Step : 2
    int index = 0;
    changeValueFromPreorder(root, ans, index);

    cout<<"After Heapifing"<<endl;
    lvlOrderTraversal(root);

    return 0;
}