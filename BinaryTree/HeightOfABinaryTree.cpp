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
};

node* buildTree(node* root){
    int data;
    cout<<"Enter data "<<endl;
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
}

int heightOfTree(node* root){
    //Base case.
    if(root == NULL){
        return 0;
    }
    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);

    int ans = max(left, right) + 1;

    return ans;
}

pair<int, int> fastDiameter(node* root){
    //Base case.
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = fastDiameter(root->left);
    pair<int,int> right = fastDiameter(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int,int> ans;
    ans.first = max(op1, max(op2,op3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameter(node* root){
    return fastDiameter(root).first;
    /* if(root == NULL){
        return 0;
    }
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = heightOfTree(root->left) + heightOfTree(root->right) + 1;

    int ans = max(op1, max(op2,op3));

    return ans; */
}

int main()
{
    node* root = NULL;
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1.
    root = buildTree(root);

    cout<<"Height of Binary Tree is "<<heightOfTree(root)<<endl;

    cout<<"Maximum Diameter of the Binary Tree is "<<diameter(root)<<endl;

    return 0;
}