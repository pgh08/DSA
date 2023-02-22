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

node* buildBST(node* root, int d){
    if(root == NULL){
        root = new node(d);
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

void takingInput(node* &root){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;

    while(data != -1){
        root = buildBST(root, data);
        cin>>data;
    }
}

void PredSucc(node* root, pair<int,int> &ans, const int key){
    if(root == NULL){
        return;
    }
    if(root->data == key){
        //Finding maximum value in the left left subtree.
        if(root->left != NULL){
            node* temp = root->left;
            while(temp->right != NULL){
                temp = temp->right;
            }
            ans.first = temp->data;
        }
        //Finding minimum value in the left left subtree.
        if(root->right != NULL){
            node* temp = root->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            ans.second = temp->data;
        }
    }
    //If key is smaller than root's data go to the left subtree.
    if(key < root->data){
        ans.second = root->data;
        PredSucc(root->left, ans, key);
    }
    else{
    //If key is greater than root's data go to the right subtree.
        ans.first = root->data;
        PredSucc(root->right, ans, key);
    }
}

int main()
{   
    const int key = 65;
    node* root = NULL;
    //50 30 20 40 70 60 80 -1.
    takingInput(root);
    //Pair value is Predecessor and Successor.
    pair<int,int> ans;
    PredSucc(root, ans, key);

    cout<<"Predecessor is : "<<ans.first<<endl;
    cout<<"Successor is : "<<ans.second<<endl;

    return 0;
}