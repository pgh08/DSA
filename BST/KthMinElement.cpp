#include<iostream>
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
    if(root->data > d){
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

int KthSmallestElement(TreeNode* root, int &i, const int k){
    if(root == nullptr){
        return -1;
    }
    int left = KthSmallestElement(root->left, i, k);
    if(left != -1){
        return left;
    }
    i++;
    if(i == k){
        return root->data;
    }
    return KthSmallestElement(root->right, i, k);
}

int main()
{
    TreeNode* root = nullptr;
    //5 8 4 2 3 10 6 7 -1.
    takingInput(root);

    const int k = 3;

    int i = 0;

    int ans = KthSmallestElement(root, i, k);

    cout<<k<<"rd smallest element is : "<<ans<<endl;

    return 0;
}