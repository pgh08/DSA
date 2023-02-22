#include<iostream>
#include<map>
#include<queue>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
    
    TreeNode(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

    ~TreeNode(){};
};

TreeNode* buildTree(TreeNode* root){
    int value;
    cout<<"Enter the value "<<endl;
    cin>>value;
    root = new TreeNode(value);

    if(value == -1){
        return NULL;
    }

    cout<<"Enter the data for left of "<<root->data<<" TreeNode"<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for right of "<<root->data<<" TreeNode"<<endl;
    root->right = buildTree(root->right);

    return root;
}

TreeNode* createMapping(TreeNode* root, map<TreeNode*,TreeNode*> &TreeNodeToParent, int target){
    TreeNode* res = NULL;
    //Level Order Traversal.
    queue<TreeNode*> q;
    q.push(root);
    TreeNodeToParent[root] = NULL;

    while(!q.empty()){

        TreeNode* front = q.front();
        q.pop();

        if(front->data == target){
            res = front;
        }

        if(front->left){
            q.push(front->left);
            TreeNodeToParent[front->left] = front;
        }

        if(front->right){
            q.push(front->right);
            TreeNodeToParent[front->right] = front;
        }
    }
    return res;
}

int burningTime(TreeNode* targetTreeNode, map<TreeNode*,TreeNode*> &TreeNodeToParent){
    map<TreeNode*,bool> visited;
    queue<TreeNode*> q;
    q.push(targetTreeNode);
    visited[targetTreeNode] = true;

    int ans = 0;

    while(!q.empty()){
        int size = q.size();
        bool flag = false;

        for(int i=0; i<size; i++){
            TreeNode* front = q.front();
            q.pop();
            
            //Checking left TreeNode if visited and burned.
           if(front->left && !visited[front->left]){
                flag = true;
                q.push(front->left);
                visited[front->left] = true;
            }
            //Checking right TreeNode if visited and burned.
            if(front->right && !visited[front->right]){
                flag = true;
                q.push(front->right);
                visited[front->right] = true;
            }
            //Checking root TreeNode if visited and burned.
            if(TreeNodeToParent[front] && !visited[TreeNodeToParent[front]]){
                flag = true;
                q.push(TreeNodeToParent[front]);
                visited[TreeNodeToParent[front]] = true;
            }
        }
        if(flag == true){
            ans++;
        }
    }
    return ans;
}

void inorder(TreeNode* root){
    if(root == nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    int target;
    cout<<"Enter target TreeNode"<<endl;
    cin>>target;

    TreeNode* root = NULL;
    //1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 -1 6 -1 9 -1 10 -1 -1.
    root = buildTree(root);

    map<TreeNode*,TreeNode*> TreeNodeToParent;
    TreeNode* targetTreeNode = createMapping(root, TreeNodeToParent, target);

    int ans = burningTime(targetTreeNode, TreeNodeToParent);

    cout<<"Time required to burn entire binary tree is : "<<ans<<endl;

    return 0;
}