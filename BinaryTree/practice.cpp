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
};

TreeNode* buildTree(TreeNode* root){
    int value;
    cout<<"Enter the data"<<endl;
    cin>>value;
    root = new TreeNode(value);

    if(value == 0){
        return nullptr;
    }

    cout<<"Enter the data for the left of "<<root->data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for the right of "<<root->data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void getKSumPaths(TreeNode* root, vector<int> &path, vector<vector<int>> &ans, int &count, int k){
    // Base Case.
    if(root == nullptr){
        return;
    }

    path.push_back(root->data);
    getKSumPaths(root->left, path, ans, count, k);
    getKSumPaths(root->right, path, ans, count, k);

    int size = path.size() - 1;
    vector<int> temp;
    int sum = 0;

    for(int i=size; i>=0; i--){
        temp.push_back(path[i]);
        sum += path[i];
        if(sum == k){
            count++;
            ans.push_back(temp);
        }
    }
    // Backtracking.
    path.pop_back();
}

int main()
{
    TreeNode* root = nullptr;
    // 
    root = buildTree(root);

    int count = 0;
    vector<int> path;
    vector<vector<int>> ans;

    int k;
    cout<<"Enter the value of target K"<<endl;
    cin>>k;



    return 0;
}