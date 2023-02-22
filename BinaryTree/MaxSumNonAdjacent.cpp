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

    cout<<"Enter data for left of "<<root->data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for right of "<<root->data<<endl;
    root->right = buildTree(root->right);

    return root;
}

pair<int,int> maxSumNonAdajacent(node* root){
    //Base case.
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    pair<int,int> leftAns = maxSumNonAdajacent(root->left);
    pair<int,int> rightAns = maxSumNonAdajacent(root->right);

    pair<int,int> ans;
    ans.first = root->data + leftAns.second + rightAns.second;
    ans.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);

    return ans;
}

int main()
{
    node* root = NULL;
    //1 2 1 -1 -1 -1 3 4 -1 -1 5 -1 -1.
    root = buildTree(root);
    pair<int,int> ans = maxSumNonAdajacent(root);

    cout<<"Maximum sum of non-adjacent node is : "<<max(ans.first, ans.second)<<endl;

    return 0;
}