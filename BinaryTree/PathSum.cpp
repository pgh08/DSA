// Given a Binary Tree find if there is any path which sums up to targetSum.
#include<iostream>
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

    ~TreeNode(){}
};

TreeNode* buildTree(TreeNode* root){
    int value;
    cout<<"Enter the data"<<endl;
    cin>>value;
    root = new TreeNode(value);

    if(value == -1){
        return nullptr;
    }

    cout<<"Enter the data for left of "<<root->data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for right of "<<root->data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void checkPath(TreeNode* root, int &sum, const int targetSum, bool &ans, vector<int> &path, vector<vector<int>> &targetSumPath){
    // Base Case.
    if(root == nullptr){
        return;
    }

    sum = sum + root->data;
    path.push_back(root->data);
    
    checkPath(root->left, sum, targetSum, ans, path, targetSumPath);
    checkPath(root->right, sum, targetSum, ans, path, targetSumPath);

    if((root->left == nullptr && root->right == nullptr) && sum == targetSum){
        ans = true;
        targetSumPath.push_back(path);
    }

    // Back Tracking.
    sum = sum - root->data;
    path.pop_back();
}

int main()
{
    TreeNode* root = nullptr;
    // 5 4 11  7 -1 -1 2 -1 -1 -1 8 13 -1 -1 4 -1 1 -1 -1.
    root = buildTree(root);

    int targetSum;
    
    cout<<"Enter the targetSum"<<endl;
    cin>>targetSum;

    int sum = 0;
    
    bool ans = false;
    vector<vector<int>> targetSumPath;
    vector<int> path;
    

    checkPath(root, sum, targetSum, ans, path, targetSumPath);

    if(ans){
        cout<<"There is a Path in a Binary Tree which sum up to targetSum"<<endl;
        cout<<"The Paths are : "<<endl;
        for(int i=0; i<targetSumPath.size(); i++){
            for(int j=0; j<targetSumPath[i].size(); j++){
                cout<<targetSumPath[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"No path in a binary which can sum up to targetSum"<<endl;
    }

    return 0;
}
