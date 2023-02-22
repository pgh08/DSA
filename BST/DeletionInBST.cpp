#include<iostream>
#include<queue>
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

void lvlOrderTraversal(node* root){
    if(root == NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }

}

node* minVal(node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

node* deleteANode(node* root, int value){
    if(root == NULL){
        return NULL;
    }
    if(root->data == value){
        //Zero child.
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //One child.
        //1. Left child.
        if(root->left != NULL && root->right == NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
        //2. Right child.
        if(root->left == NULL && root->right != NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }

        //Two child.
        if(root->left != NULL && root->right != NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteANode(root->right, mini);
            return root;
        }
    }
    else if(root->data > value){
        root->left = deleteANode(root->left, value);
        return root;
    }
    else{
        root->right = deleteANode(root->right, value);
        return root;
    }
}

int main()
{
    node* root = NULL;
    //10 8 21 7 27 5 4 3 -1.
    takeInput(root);

    cout<<"Tree before deleting the node"<<endl;
    lvlOrderTraversal(root);
    cout<<endl;

    int value;
    cout<<"Enter the node value to delete"<<endl;
    cin>>value;

    root = deleteANode(root, value);

    cout<<"Tree after deleting the node"<<endl;
    lvlOrderTraversal(root);
    cout<<endl;

    return 0;
}