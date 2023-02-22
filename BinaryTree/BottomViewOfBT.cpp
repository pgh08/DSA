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

void bottomView(node* root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    map<int,int> om;
    queue<pair<node*,int>> q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<node*,int> temp = q.front();
        q.pop();

        node* firstNode = temp.first;
        int HD = temp.second;

        om[HD] = firstNode->data;

        if(firstNode->left){
            q.push(make_pair(firstNode->left,HD-1));
        }
        if(firstNode->right){
            q.push(make_pair(firstNode->right,HD+1));
        }
    }
    for(auto i: om){
        ans.push_back(i.second);
    }
}

int main()
{
    node* root = NULL;
    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1.
    root = buildTree(root);
    cout<<endl;

    vector<int> ans;
    bottomView(root, ans);
    cout<<"Bottom View is : "<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}