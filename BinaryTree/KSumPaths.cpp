//Given a Binary Tree find the number of paths which has sum equal to target sum k.
/*
Algorithm :
    1. Keep track of path element's data using vector.
    2. If sum of any number of path elements leads to targetSum k increment the count.
    3. Pop back the vector element after check for targetSum k in each path.
*/
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

    if(data == 0){
        return NULL;
    }

    cout<<"Enter data for left of "<<root->data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for right of "<<root->data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void kSumPath(TreeNode* root, int &count, vector<int> path, int k, vector<vector<int>> &ans){
    //Base case.
    if(root == NULL){
        return;
    }
    path.push_back(root->data);
    kSumPath(root->left, count, path, k, ans);
    kSumPath(root->right, count, path, k, ans);
    
    int size = path.size()-1;
    int sum = 0;
    vector<int> temp;

    for(int i=size; i>=0; i--){
        temp.push_back(path[i]);
        sum += path[i];
        if(sum == k){
            count++;
            ans.push_back(temp);
        }
    }
    //Backtracking.
    path.pop_back();
}

int main()
{
    TreeNode* root = NULL;
    //1 2 0 0 3 0 0.
    //1 3 2 0 0 1 1 0 0 0 -1 4 1 0 0 2 0 0 5 0 6 0 0.
    root = buildTree(root);

    int count = 0;
    int sum = 0;
    int curr = 0;
    int k;
    cout<<"Enter the value of k : "<<endl;
    cin>>k;
    vector<int> path;
    vector<vector<int>> ans;
    kSumPath(root, count, path, k, ans);

    cout<<"Number of Paths "<<count<<endl;

    cout<<"Path combinations are : "<<endl;

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}