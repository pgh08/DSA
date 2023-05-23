#include<iostream>
#include<vector>
#include<algorithm>
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

    if(data == -1){
        return NULL;
    }
    //Left Insertion.
    cout<<"Enter data for inserting in left of "<<root->data<<endl;
    root->left = buildTree(root->left);
    //Right Insertion.
    cout<<"Enter data for inserting in right of "<<root->data<<endl;
    root->right = buildTree(root->right);

    return root;
}

// Morris Preorder Traversal.
void MorrisPreorderTraversal(TreeNode* root){
    TreeNode* curr = root;
    TreeNode* predecessor = NULL;

    while(curr != NULL){
        if(curr->left == NULL){
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else{
            predecessor = curr->left;
            while(predecessor->right != NULL && predecessor->right != curr){
                predecessor = predecessor->right;
            }

            if(predecessor->right == NULL){
                cout<<curr->data<<" ";
                predecessor->right = curr;
                curr = curr->left;
            }
            else{
                predecessor->right = NULL;
                curr = curr->right;
            }
        }
    }
}

// Morris Inorder Traversal.
void MorrisInorderTraversal(TreeNode* root){
    TreeNode* curr = root;
    TreeNode* predecessor = NULL;
    while(curr != NULL){
        if(curr->left == NULL){
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else{
            predecessor = curr->left;
            while(predecessor->right != NULL && predecessor->right != curr){
                predecessor = predecessor->right;
            }

            if(predecessor->right == NULL){
                predecessor->right = curr;
                curr = curr->left;
            }
            else{
                predecessor->right = NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
    }
}

vector<int> MorrisPostOrderTraversal(TreeNode* root){
    TreeNode* curr = root;
    TreeNode* predecessor = NULL;
    vector<int> postOrder;

    while(curr != NULL){
        if(curr->right == NULL){
            postOrder.push_back(curr->data);
            curr = curr->left;
        }
        else{
            predecessor = curr->right;
            while(predecessor->left != NULL && predecessor->left != curr){
                predecessor = predecessor->left;
            }

            if(predecessor->left == NULL){
                postOrder.push_back(curr->data);
                predecessor->left = curr;
                curr = curr->right;
            }
            else{
                predecessor->left = NULL;
                curr = curr->left;
            }
        }
    }
    return postOrder;
}

void print(vector<int> &postOrder){
    for(auto x : postOrder){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main()
{
    TreeNode* root = NULL;
    //1 2 4 -1 7 -1 -1 5 -1 -1 3 -1 6 -1 -1.
    root = buildTree(root);

    // Inorder.
    // MorrisInorderTraversal(root);

    // Preorder.
    // MorrisPreorderTraversal(root);

    // Postorder.
    vector<int> postOrder = MorrisPostOrderTraversal(root);

    reverse(postOrder.begin(), postOrder.end());

    print(postOrder);

    return 0;
}