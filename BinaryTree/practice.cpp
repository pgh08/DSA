#include<iostream>
#include<queue>
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

    cout<<"Enter the data for left of "<<root->data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for right of "<<root->data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void lvlOrderTraversal(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();

        if(temp == nullptr){
            cout<<endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
            cout<<temp->data<<" ";

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

pair<bool,int> fastBalance(TreeNode* root){
    if(root == nullptr){
        return {true,0};
    }
    pair<bool,int> leftAns = fastBalance(root->left);
    pair<bool,int> rightAns = fastBalance(root->right);
    bool diff = abs(leftAns.second - rightAns.second) <= 1;

    pair<bool,int> ans;
    ans.second = max(leftAns.second, rightAns.second) + 1;

    if(leftAns.first && rightAns.first && diff){
        ans.first = true;
    }
    else{
        ans.first = false;
    }
    return ans;
}

bool isBalancedTree(TreeNode* root){
    return fastBalance(root).first;
}

int main()
{
    TreeNode* root = nullptr;
    //1 2 3 -1 -1 4 -1 -1 -1.
    root = buildTree(root);

    lvlOrderTraversal(root);

    if(isBalancedTree(root)){
        cout<<"Tree is balanced"<<endl;
    }
    else{
        cout<<"Tree is not balanced"<<endl;
    }

    return 0;
}