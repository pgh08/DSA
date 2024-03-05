// Given a binary tree with N nodes, in which each node value represents number of candies present at that node. In one move, one may choose two adjacent nodes and move only one candy from one node to another (the move may be from parent to child, or from child to parent.) 
// The task is to find the number of moves required such that every node has exactly one candy.
// Note that the testcases are framed such that it is always possible to achieve a configuration in which every node has exactly one candy, after some moves.
#include<iostream>
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

TreeNode* buildTree(TreeNode* root){
    int val;
    cout<<"Enter the value of the node"<<endl;
    cin>>val;
    root = new TreeNode(val);

    if(val == -1){
        return nullptr;
    }

    cout<<"Enter the data for left of "<<root->data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for right of "<<root->data<<endl;
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

int solve(TreeNode* root, int &ans){
    // Base Case.
    if(root == nullptr){
        return 0;
    }

    int left = solve(root->left, ans);
    int right = solve(root->right, ans);

    ans += abs(left) + abs(right);

    return root->data+left+right-1;
}

int main()
{
    TreeNode* root = nullptr;
    root = buildTree(root); // 4 0 0 -1 -1 0 -1 -1 1 -1 -1.

    // printing.
    // lvlOrderTraversal(root);

    int ans = 0;
    solve(root, ans);

    cout<<"Moves required to distribute candies are : "<<ans<<endl; // 5.

    return 0;
}