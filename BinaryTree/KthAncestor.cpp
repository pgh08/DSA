//Given a binary tree find K'th ancestor for a given node.
/*
Algorithm : 
    1. Using head recursion : 
        --> Return the root if found a input given node.
        --> Check whether it is a leftAns or rightAns.
        --> While checking reduce the value of input k.
        --> Once k reduced to zero set it to max value of int so the the ans is locked.
        --> Time Complexity : O(n), Space Complexity : O(n).

    2. Using Map : 
        --> Create TreeNode to ancestor mapping for each node using Level Order Traversal.
        --> Use this mapping to increment the count till it is equal to k and break out of the loop.
        --> If that node value becomes equal to root return -1.
        --> Time Complexity : O(n), Space Complexity : O(n).
*/
#include<iostream>
#include<limits.h>
#include<queue>
#include<unordered_map>
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

    cout<<"Enter data for left of "<<root->data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for right of "<<root->data<<endl;
    root->right = buildTree(root->right);

    return root;
}

TreeNode* Ancestor(TreeNode* root, int &k, int n){
    //Base case.
    if(root == nullptr){
        return nullptr;
    }
    if(root->data == n){
        return root;
    }

    TreeNode* leftAns = Ancestor(root->left, k, n);
    TreeNode* rightAns = Ancestor(root->right, k, n);

    if(leftAns != nullptr && rightAns == nullptr){
        k--;
        if(k <= 0){
            //For locking ans value.
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if(leftAns == nullptr && rightAns != nullptr){
        k--;
        if(k <= 0){
            //For locking ans value.
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return nullptr;
}

int main()
{
    TreeNode* root = nullptr;
    //1 2 4 -1 -1 5 -1 -1 3 -1 -1.
    root = buildTree(root);
    int k,n;
    cout<<"Enter K'th Ancestor number "<<endl;
    cin>>k;
    cout<<"Enter from which TreeNode "<<endl;
    cin>>n;
    
    TreeNode* ans = Ancestor(root, k, n);

    int res = ans==nullptr? -1 : ans->data;
    cout<<"Answer is: "<<res<<endl;

    return 0;
}