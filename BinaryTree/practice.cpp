#include<iostream>
#include<stack>
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
        TreeNode* front = q.front();
        q.pop();

        if(front == nullptr){
            cout<<endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
            cout<<front->data<<" ";

            if(front->left){
                q.push(front->left);
            }
            
            if(front->right){
                q.push(front->right);
            }
        }
    }
}

void Inorder(TreeNode* root){
    // Base Case.
    // if(root == nullptr){
    //     return;
    // }
    // Inorder(root->left);
    // cout<<root->data<<" ";
    // Inorder(root->right);

    stack<TreeNode*> st;
    TreeNode* curr = root;

    while(curr != nullptr || st.empty() == false){
        while(curr != nullptr){
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        cout<<curr->data<<" ";
        curr = curr->right;
    }
    cout<<endl;
}

void Preorder(TreeNode* root){
    // Base Case.
    if(root == nullptr){
        return;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(TreeNode* root){
    // Base Case.
    if(root == nullptr){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    TreeNode* root = nullptr;
    // 1 2  3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1.
    root = buildTree(root);

    cout<<"Level Order Traversal is :"<<endl;
    lvlOrderTraversal(root);

    cout<<"Inorder Traversal is :"<<endl;
    Inorder(root);
    cout<<endl;

    cout<<"Preorder Traversal is :"<<endl;
    Preorder(root);
    cout<<endl;

    cout<<"Postorder Traversal is :"<<endl;
    Postorder(root);
    cout<<endl;

    return 0;
}