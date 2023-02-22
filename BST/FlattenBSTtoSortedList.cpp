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

void MorrisTraversal(TreeNode* root, vector<int> &ans){
    TreeNode* curr = root;
    while(curr != nullptr){
        if(curr->left == nullptr){
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else{
            TreeNode* predecessor = curr->left;
            while(predecessor->right != nullptr && predecessor->right != curr){
                predecessor = predecessor->right;
            }

            if(predecessor->right == nullptr){
                predecessor->right = curr;
                curr = curr->left;
            }
            else{
                predecessor->right = nullptr;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
}

void printing(TreeNode* &newRoot){
    TreeNode* temp = newRoot;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;
}

int main()
{
    TreeNode* root = nullptr;
    //5 3 6 2 4 7 -1.
    takingInput(root);

    vector<int> ans;

    MorrisTraversal(root, ans);

    int n = ans.size();
    //Making Linked List.
    TreeNode* newRoot = new TreeNode(ans[0]);

    TreeNode* curr = newRoot;

    for(int i=1; i<n; i++){
        TreeNode* temp = new TreeNode(ans[i]);

        curr->left = nullptr;
        curr->right = temp;
        curr = temp;
    }

    curr->left = nullptr;
    curr->right = nullptr;

    printing(newRoot);

    return 0;
}