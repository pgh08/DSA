#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node* left;
        node* right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root)
{
    cout<<"Enter the data :"<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter the data to be inserted on the left side of the tree "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data to be inserted on the right side of the tree "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}
//In-order Traversal(LNR).
void LNRTrav(node* root)
{
    if(root == NULL){
        return;
    }

    LNRTrav(root->left);
    cout<<root->data<<" ";
    LNRTrav(root->right);
}
//Pre-order Traversal(NLR).
void NLRTrav(node* root)
{
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    NLRTrav(root->left);
    NLRTrav(root->right);
}
//Post-order Traversal(NLR).
void LRNTrav(node* root)
{
    if(root == NULL){
        return;
    }

    LRNTrav(root->left);
    LRNTrav(root->right);
    cout<<root->data<<" ";
}

node* buildfromlevel(node* root)
{
    queue<node*>q;
    cout<<"Enter the root node data :"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while (!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter the left node for "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter the right node for "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }

    }   
    return root;
}

int main()
{
    node* root= NULL;

    root = buildfromlevel(root);
//10 9 8 -1 -1  7 -1 -1 11 12 -1 -1 13 -1 -1
//    root = buildTree(root);

    cout<<"In-order Traversal"<<" ";
    LNRTrav(root);

    cout<<endl<<"Pre-order Traversal"<<" ";
    NLRTrav(root);

    cout<<endl<<"Post-order Traversal"<<" ";
    LRNTrav(root);

    return 0;
}