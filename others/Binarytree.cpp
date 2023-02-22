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
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    
    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting in left "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}
//Level order traversal.
void lvlordtrav(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()){
        node* temp = q.front();
        q.pop();
    //If full level is already traversed.
        if(temp == NULL){
            cout<<endl;
    //If queue still has one child node.
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
    //Checking the left elements of tree.
            if(temp->left){
                q.push(temp->left);
            }
    //Checking the right elements of tree.
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    
}
//Reverse level order traversal.
void revlvlordtrav(node* root)
{
    queue<node*>q;
    stack<node*>s;
    q.push(root);

    while (!q.empty()){
        node* temp = q.front();
        q.pop();
        s.push(temp);
 /*   //If full level is already traversed.
        if(temp == NULL){
            cout<<endl;
    //If queue still has one child node.
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{*/
    //Checking the right elements of tree.
            if(temp->right){
                q.push(temp->right);
            }
    //Checking the left elements of tree.
            if(temp->left){
                q.push(temp->left);
            }
        }
    while (!s.empty()){
        node* temp = s.top();
        cout<<temp->data<<" ";
        s.pop();
    }
}   

//Driver code.
int main()
{
    node* root = NULL;
//creating a Tree.
//Input to be given:
//10 9 8 -1 -1  7 -1 -1 11 12 -1 -1 13 -1 -1 
    root = buildTree(root);
//Calling level order traversal.
    lvlordtrav(root);
//Calling Reverse level order traversal.
    revlvlordtrav(root);
    return 0;
}