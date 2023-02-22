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

void takeInput(node* &root){
    int data;
    cout<<"Enter data"<<endl;
    cin>>data;

    while(data != -1){
        root = buildBST(root, data);
        cin>>data;
    }
}

bool searchElement(node* root, int element){
    if(root == NULL){
        return false;
    }
    if(element < root->data){
        searchElement(root->left, element);
    }
    else{
        searchElement(root->right, element);
    }
    if(root->data == element){
        return true;
    }
    return false;
}

int main()
{
    node* root = NULL;
    //10 8 21 7 27 5 4 3 -1.
    takeInput(root);

    int element;
    cout<<"Enter element for searching"<<endl;
    cin>>element;
    
    if(searchElement(root, element)){
        cout<<"Element found"<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }

    return 0;
}