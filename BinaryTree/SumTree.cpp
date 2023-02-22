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

pair<bool,int> fastSum(node* root){
    //Base case.
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    if(root->left == NULL && root->right == NULL){
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }

    pair<bool,int> leftAns = fastSum(root->left);
    pair<bool,int> rightAns = fastSum(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;

    bool condition = root->data == leftAns.second + rightAns.second;
    pair<bool,int> ans;

    if(left && right && condition){
        ans.first = true;
        ans.second = 2*root->data;
    }
    else{
        ans.first = false;
        ans.second = -1;
    }
    return ans;
}

bool isSum(node* root){
    return fastSum(root).first;
}

int main()
{
    node* root =  new node(3);
    root->left = new node(1);
    root->right = new node(1);
    root->right->right = new node(1);
    root->left->left = root->left->right = NULL;
    root->right->right->left = root->right->right->right = NULL;

    if(isSum(root)){
        cout<<"It is a Sum Tree"<<endl;
    }
    else{
        cout<<"It is not a Sum Tree"<<endl;
    }

    return 0;
}