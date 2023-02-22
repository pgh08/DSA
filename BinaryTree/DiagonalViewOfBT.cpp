//Given a binary print its diagonal view.
/*
Algorithm : 
    1. For left Traversal vertical distances changes.
    2. For right Traversal vertical distance remains the same.
    3. Time complexity : O(n*log(n)), Space complexity : O(n).
*/
#include<iostream>
#include<queue>
#include<map>
#include<vector>
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
    cout<<"Enter the data for left of "<<root->data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for right of "<<root->right<<endl;
    root->right = buildTree(root->right);

    return root;
}

void diagonalView(TreeNode* root, int verticalDistance, map<int,vector<int>> &verticalDistanceToNodeValue){
    if(root == nullptr){
        return;
    }
    verticalDistanceToNodeValue[verticalDistance].push_back(root->data);
    //Increase the vertical distance if it is left child.
    diagonalView(root->left, verticalDistance+1, verticalDistanceToNodeValue);
    //Vertical distance remains same for right child.
    diagonalView(root->right, verticalDistance, verticalDistanceToNodeValue);
}

int main()
{
    TreeNode* root = nullptr;
    //8 3 1 -1 4 -1 -1 6 -1 7 -1 -1 10 -1 14 13 -1 -1 -1.
    root = buildTree(root);

    map<int,vector<int>> verticalDistanceToNodeValue;
    int verticalDistance = 0;
    diagonalView(root, verticalDistance, verticalDistanceToNodeValue);

    for(auto pr: verticalDistanceToNodeValue){
        for(auto it: pr.second){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    return 0;
}