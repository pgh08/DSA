#include<bits/stdc++.h>
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
};
 TreeNode* buildTree(TreeNode* root){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    root = new TreeNode(data);

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

//Building Tree iteratively.
/* TreeNode* buildTree(TreeNode* root){
    int data;
    cout<<"Enter the value"<<endl;
    cin>>data;
    root = new TreeNode(data);
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while(curr != nullptr || st.empty() == false){
        while(curr != nullptr){
            st.push(curr);
            cout<<"Enter the left TreeNode data for "<<curr->data<<endl;
            cin>>data;
            if(data != -1){
                curr->left = new TreeNode(data);
            }
            curr = curr->left;
        }
        curr = st.top();
        st.pop();

        cout<<"Enter the right TreeNode data for "<<curr->data<<endl;
        cin>>data;
        if(data != -1){
            curr->right = new TreeNode(data);
        }
        curr = curr->right;
    }
    return root;
} */

void levelOrderTraversal(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
     TreeNode* temp = q.front();
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

void reverseLevelOrderTraversal(TreeNode* root){
    stack<TreeNode*> s;
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()){
     TreeNode* temp = q.front();
        q.pop();
        s.push(temp);

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }

    while(!s.empty()){
        cout<<s.top()->data<<" ";
        s.pop();
    }
}

void InorderTraversal(TreeNode* root){
    //Base case.
    if(root == NULL){
        return;
    }
    //Recursive call for left half.
    InorderTraversal(root->left);
    //Printing middle TreeNode.
    cout<<root->data<<" ";
    //Recursive call for right half.
    InorderTraversal(root->right);
}

//Iterative Inorder and Preorder.
/* void Inorder(Tre TreeNode* root){
    TreeNode* curr = root;
    stack<TreeNode*> st;


    while(curr != nullptr || st.empty() == false){
        while(curr != nullptr){
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        cout<<curr->data<<" ";

        curr = curr->right;
    }
    cout<<endl;
}

void Preorder(TreeNode* root){
    stack<TreeNode*> st;
    st.push(root);

    while(st.empty() == false){
        TreeNode* curr = st.top();
        st.pop();
        cout<<curr->data<<" ";

        if(curr->right){
            st.push(curr->right);
        }
        if(curr->left){
            st.push(curr->left);
        }
    }
    cout<<endl;
} */

void PreorderTraversal(TreeNode* root){
    //Base case.
    if(root == NULL){
        return;
    }
    //Printing middle TreeNode.
    cout<<root->data<<" ";
    //Recursive call for left half.
    PreorderTraversal(root->left);
    //Recursive call for right half.
    PreorderTraversal(root->right);
}

void PostOrderTraversal(TreeNode* root){
    //Base case.
    if(root == NULL){
        return;
    }
    //Recursive call for left half.
    PostOrderTraversal(root->left);
    //Recursive call for right half.
    PostOrderTraversal(root->right);
    //Printing middle TreeNode.
    cout<<root->data<<" ";
}

void buildFromLevelOrder(TreeNode* &root){
    queue<TreeNode*> q;
    cout<<"Enter data for root"<<endl;
    int data;
    cin>>data;
    root = new TreeNode(data);
    q.push(root);

    while(!q.empty()){
     TreeNode* temp = q.front();
        q.pop();
        
        cout<<"Enter left TreeNode for "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData != -1){
            temp->left = new TreeNode(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right TreeNode for "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData != -1){
            temp->right = new TreeNode(rightData);
            q.push(temp->right);
        }
    }   
}

int main()
{
    TreeNode* root = NULL;

    buildFromLevelOrder(root);

    /* // Tree : 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1.
    root = buildTree(root);

    cout<<"Printing level order traversal"<<endl;
    levelOrderTraversal(root);

    cout<<endl;
    cout<<"Printing Reverse order travelsal"<<endl;
    reverseLevelOrderTraversal(root);

    cout<<endl;
    cout<<"Printing Inorder Traversal"<<endl;
    InorderTraversal(root);

    cout<<endl;
    cout<<"Printing Preorder Traversal"<<endl;
    PreorderTraversal(root);

    cout<<endl;
    cout<<"Printing Postorder Traversal"<<endl;
    PostOrderTraversal(root); */

    return 0;
}