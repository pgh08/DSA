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
    //Left Insertion.
    cout<<"Enter data for inserting in left of "<<root->data<<endl;
    root->left = buildTree(root->left);
    //Right Insertion.
    cout<<"Enter data for inserting in right of "<<root->data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void verticalTraversal(node* root, vector<int> &ans){
    //Numberline (Horizontal Distance (HD))-2 -1 0 1 2 3 for this case.
    //Map for hold HD and another Map inside it for holding level and level elements i.e result.
    map<int, map<int,vector<int>>> nodes;
    //In this case we want to do level order traversal so we need nested Queue.
    //Queue has pair of node for holding Node and another pair inside it for holding HD and level.
    queue<pair<node*, pair<int,int>>> q;
    if(root == NULL){
        return;
    }

    q.push(make_pair(root,make_pair(0,0)));

    while(!q.empty()){
        pair<node*,pair<int,int>> temp = q.front();
        q.pop();

        node* frontNode = temp.first;
        int HD = temp.second.first;
        int lvl = temp.second.second;

        nodes[HD][lvl].push_back(frontNode->data);
        //Left part.
        if(frontNode->left){
            q.push(make_pair(frontNode->left,make_pair(HD-1,lvl+1)));
        }
        //Right part.
        if(frontNode->right){
            q.push(make_pair(frontNode->right,make_pair(HD+1,lvl+1)));
        }
    }
    for(auto i: nodes){
        for(auto j:i.second){
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
    }
}

int main()
{
    node* root = NULL;
    //1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1.
    root = buildTree(root);
    vector<int> ans;
    verticalTraversal(root, ans);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}