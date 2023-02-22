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
    //Left Insertion.
    cout<<"Enter data for inserting in left of "<<root->data<<endl;
    root->left = buildTree(root->left);
    //Right Insertion.
    cout<<"Enter data for inserting in right of "<<root->data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void MorrisTraversal(node* root){
    node* curr = root;
    node* predecessor = NULL;
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

int main()
{
    node* root = NULL;
    //1 2 4 -1 7 -1 -1 5 -1 -1 3 -1 6 -1 -1.
    root = buildTree(root);

    MorrisTraversal(root);

    return 0;
}