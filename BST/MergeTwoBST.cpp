#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

    TreeNode(int d){
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }

    ~TreeNode(){}
};

TreeNode* buildBST(TreeNode* root, int d){
    //Base case.
    if(root == nullptr){
        root = new TreeNode(d);
        return root;
    }
    if(root->data > d){
        root->left = buildBST(root->left, d);
    }
    else{
        root->right = buildBST(root->right, d);
    }

    return root;
}

void takingInput(TreeNode* &root){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;

    while(data != -1){
        root = buildBST(root, data);
        cin>>data;
    }
}

void InorderTraversal(TreeNode* root, vector<int> &Inorder){
    if(root == nullptr){
        return;
    }
    InorderTraversal(root->left, Inorder);
    Inorder.push_back(root->data);
    InorderTraversal(root->right, Inorder);
}

void MergeInorder(vector<int> &Inorder1, vector<int> &Inorder2, vector<int> &finalInorder){
    int firstLen = Inorder1.size();
    int secondLen = Inorder2.size();

    int firstIndex = 0;
    int secondIndex = 0;

    while(firstIndex < firstLen && secondIndex < secondLen){
        if(Inorder1[firstIndex] <= Inorder2[secondIndex]){
            finalInorder.push_back(Inorder1[firstIndex++]);
        }
        else{
            finalInorder.push_back(Inorder2[secondIndex++]);
        }
    }
    //If Inorder1 is not empty.
    while(firstIndex < firstLen){
        finalInorder.push_back(Inorder1[firstIndex++]);
    }
    //If Inorder2 is not empty.
    while(secondIndex < secondLen){
        finalInorder.push_back(Inorder2[secondIndex++]);
    }
}

TreeNode* builFromInorder(vector<int> &finalInorder, int start, int end){
    //Base case.
    if(start > end){
        return nullptr;
    }
    int mid = start + (end - start)/2;
    
    TreeNode* root = new TreeNode(finalInorder[mid]);
    //Recursive call.
    //Left part.
    root->left = builFromInorder(finalInorder, start, mid-1);
    //Right part.
    root->right = builFromInorder(finalInorder, mid+1, end);

    return root;
}

void lvlOrderTraversal(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();

        if(temp == nullptr){
            cout<<endl;
            if(!q.empty()){
                q.push(nullptr);
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

int main()
{
    TreeNode* root1 = nullptr;
    TreeNode* root2 = nullptr;
    //First Tree : 2 1 3 -1.
    //Second Tree : 4 -1.
    takingInput(root1);
    takingInput(root2);

    //Step1 : Storing inorder of 2 BSTs.
    vector<int> Inorder1;
    vector<int> Inorder2;

    InorderTraversal(root1, Inorder1);
    InorderTraversal(root2, Inorder2);

    //Step2 : Merge above 2 sorted Inorder1 and Inorder2 arrays.
    vector<int> finalInorder;
    MergeInorder(Inorder1, Inorder2, finalInorder);

    //Step3 : Creating new BST using the above finalInorder array.
    int start = 0;
    int end = finalInorder.size()-1;

    TreeNode* ans = builFromInorder(finalInorder, start, end);

    //Printing level order traversal of BST.
    lvlOrderTraversal(ans);

    return 0;
}