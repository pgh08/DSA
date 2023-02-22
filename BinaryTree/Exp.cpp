#include<iostream>
#include "Exp.h"
using namespace std;

/* node :: node(int d){
    this->data = d;
    this->left = NULL;
    this->right = NULL;
}

node* node :: buildTree(node* root){
    int data;
    cout<<"Enter Data : "<<endl;
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
} */

node :: node(){
    cout<<"Fuck this"<<endl;
}

void node :: fuckme(){
    cout<<"Fuck"<<endl;
}