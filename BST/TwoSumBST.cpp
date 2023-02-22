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

TreeNode* buildBST(TreeNode* root, int d){
    if(root == nullptr){
        root = new TreeNode(d);
        return root;
    }
    if(d < root->data){
        root->left = buildBST(root->left, d);
    }
    else{
        root->right = buildBST(root->right, d);
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

void Inorder(TreeNode* root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    Inorder(root->left, ans);
    ans.push_back(root->data);
    Inorder(root->right, ans);
}

bool TwoSum(vector<int> ans, const int k){
    int start = 0;
    int end = ans.size()-1;

    while(start < end){
        int sum = ans[start] + ans[end];
        if(sum == k){
            return true;
        }
        if(sum > k){
            end--;
        }
        else{
            start++;
        }
    }
    return false;
}

int main()
{
    TreeNode* root = nullptr;
    //5 3 6 2 4 7 -1.
    takingInput(root);

    vector<int> ans;
    
    Inorder(root, ans);

    int k;
    cout<<"Enter the target sum"<<endl;
    cin>>k;

    if(TwoSum(ans, k)){
        cout<<"Two sum possible"<<endl;
    }
    else{
        cout<<"Two sum not possible"<<endl;
    }

    return 0; 
}