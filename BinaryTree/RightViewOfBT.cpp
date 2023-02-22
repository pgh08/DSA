#include<bits/stdc++.h>
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
    cout<<"Enter the data for the left of "<<root->data<<" node"<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for the right of "<<root->data<<" node"<<endl;
    root->right = buildTree(root->right);

    return root;
}

void rightView(node* root, vector<int> &ans, int lvl){
    if(root == NULL){
        return;
    }
    if(lvl == ans.size()){
        ans.push_back(root->data);
    }
    rightView(root->right, ans, lvl+1);
    rightView(root->left, ans, lvl+1);
}

int main()
{
    node* root = NULL;
    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1.
    root = buildTree(root);
    cout<<endl;

    vector<int> ans;
    rightView(root, ans, 0);
    cout<<"Left View is : "<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}