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

pair<int,int> findMinMax(node* root){
    pair<int,int> res;
    node* temp = root;
    //Finding Minimum value of BST.
    while(temp->left != NULL){
        temp = temp->left;
    }
    res.first = temp->data;
    temp = root;
    //Finding Maximum value of BST.
    while(temp->right != NULL){
        temp = temp->right;
    }
    res.second = temp->data;

    return res;
}

int main()
{
    node* root = NULL;
    //10 8 21 7 27 5 4 3 -1.
    takingInput(root);

    pair<int,int> ans = findMinMax(root);

    cout<<"Minimum value is : "<<ans.first<<endl;
    cout<<"Maximum value is : "<<ans.second<<endl;

    return 0;
}