#include<iostream>
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

pair<bool,int> fastSum(TreeNode* root){
    //Base case.
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    if(root->left == NULL && root->right == NULL){
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }

    pair<bool,int> leftAns = fastSum(root->left);
    pair<bool,int> rightAns = fastSum(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;

    bool condition = root->data == leftAns.second + rightAns.second;
    pair<bool,int> ans;

    if(left && right && condition){
        ans.first = true;
        ans.second = 2*root->data;
    }
    else{
        ans.first = false;
        ans.second = -1;
    }
    return ans;
}

bool isSum(TreeNode* root){
    return fastSum(root).first;
}

int main()
{
    TreeNode* root =  new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(1);
    root->right->right = new TreeNode(1);
    root->left->left = root->left->right = NULL;
    root->right->right->left = root->right->right->right = NULL;

    if(isSum(root)){
        cout<<"It is a Sum Tree"<<endl;
    }
    else{
        cout<<"It is not a Sum Tree"<<endl;
    }

    return 0;
}