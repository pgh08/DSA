#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

    ~node(){}
};

node* buildTree(node* root){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for left of "<<root->data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for right of "<<root->data<<endl;
    root->right = buildTree(root->right);

    return root;
}

node* LCA(node* root, int n1, int n2){
    //Base case.
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }

    node* leftAns = LCA(root->left, n1, n2);
    node* rightAns = LCA(root->right, n1, n2);

    if(leftAns != NULL && rightAns != NULL){
        return root;
    }
    else if(leftAns != NULL && rightAns == NULL){
        return leftAns;
    }
    else if(leftAns == NULL && rightAns != NULL){
        return rightAns;
    }
    else{
        return NULL;
    }
}

int main()
{
    node* root = NULL;
    //1 2 -1 -1 3 -1 -1.
    root = buildTree(root);
    int n1,n2;
    cout<<"Enter n1 and n2 values"<<endl;
    cin>>n1>>n2;
    node* ans = LCA(root, n1, n2);
    if(ans == NULL){
        cout<<"No such Lowest Common factor"<<endl;
    }
    else{
        cout<<"Lowest Common Ancestor is : "<<ans->data<<endl;
    }

    return 0;
}