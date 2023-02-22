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
    cout<<"Enter the data for left node of "<<root->data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for right node of "<<root->data<<endl;
    root->right = buildTree(root->right);

    return root;
}

vector<int> zigzagPrint(node* root){
    vector<int> res;
    if(root == NULL){
        return res;
    }
    queue<node*> q;
    q.push(root);
    bool LeftToRight = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> temp(size);

        for(int i=0; i<size; i++){
            node* frontNode = q.front();
            q.pop();

            int index = LeftToRight? i : size-i-1;
            temp[index] = frontNode->data;
            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }
        LeftToRight = !LeftToRight;

        for(auto i: temp){
            res.push_back(i);
        }
    }
    return res;
}

int main()
{
    node* root = NULL;
    //1 2 -1 -1 3 4 -1 -1 5 -1 -1.
    root = buildTree(root);

    vector<int> ans = zigzagPrint(root);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}