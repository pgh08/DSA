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

TreeNode* InorderToBST(int start, int end, vector<int> ans){
    //Base case.
    if(start > end){
        return nullptr;
    }

    int mid = start + (end-start)/2;

    TreeNode* root = new TreeNode(ans[mid]);
    root->left = InorderToBST(start, mid-1, ans);
    root->right = InorderToBST(mid+1, end, ans);

    return root;
}

pair<int,bool> checkBalance(TreeNode* root){
    if(root == nullptr){
        pair<int,bool> p = make_pair(0,true);
        return p;
    }
    pair<int,bool> leftAns = checkBalance(root->left);
    pair<int,bool> rightAns = checkBalance(root->right);

    pair<int,bool> ans;
    ans.first = max(leftAns.first,rightAns.first) + 1;
    if(abs(leftAns.first - rightAns.first) <= 1 && checkBalance(root->left).second && checkBalance(root->right).second){
        ans.second = true;
    }
    else{
        ans.second = false;
    }

    return ans;
}

int main()
{
    TreeNode* root = nullptr;
    //50 30 60 20 40 70 80 -1.
    takingInput(root);

    cout<<"Before baalancing"<<endl;
    if(checkBalance(root).second){
        cout<<"Tree is Balanced"<<endl;
    }
    else{
        cout<<"Tree is not Balanced"<<endl;
    }

    vector<int> ans;
    MorrisTraversal(root, ans);
    
    int start = 0;
    int end = ans.size()-1;

    TreeNode* newRoot = InorderToBST(start, end, ans);

    cout<<"After baalancing"<<endl;
    if(checkBalance(newRoot).second){
        cout<<"Tree is Balanced"<<endl;
    }
    else{
        cout<<"Tree is not Balanced"<<endl;
    }

    return 0;
}