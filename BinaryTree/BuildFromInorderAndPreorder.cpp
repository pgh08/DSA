#include<iostream>
#include<map>
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

    ~TreeNode(){}
};

/* int findPosition(int *Inorder, int element, int n){
    for(int i=0; i<n; i++){
        if(Inorder[i] == element){
            return i;
        }
    }
    return -1;
} */

void createMapping(int *Inorder, map<int,int> &TreeNodeToIndex, int n){
    for(int i=0; i<n; i++){
        TreeNodeToIndex[Inorder[i]] = i;
    }
}

TreeNode* buildTree(int *Inorder, int *Preorder, int &Index, int InStartIndex, int InEndIndex, int n, map<int,int> TreeNodeToIndex){
    //Base case.
    if(Index >= n || InStartIndex > InEndIndex){
        return NULL;
    }
    //Making root TreeNode.
    int element = Preorder[Index++];
    TreeNode* root = new TreeNode(element);

    //Find Position of root TreeNode in Inorder array.
    //int pos = findPosition(Inorder, element, n);
    //Optimized approach.
    int pos = TreeNodeToIndex[element];
    //Recursive call for left half.
    root->left = buildTree(Inorder, Preorder, Index, InStartIndex, pos-1, n, TreeNodeToIndex);
    //Recursive call for right half.
    root->right = buildTree(Inorder, Preorder, Index, pos+1, InEndIndex, n, TreeNodeToIndex);

    return root;
}

void Postorder(TreeNode* root){
    //Base case.
    if(root == NULL){
        return;
    }
    //Recursive call.
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{   
    TreeNode* root = NULL;
    int n = 6;
    int Inorder[6] = {3,1,4,0,5,2};
    int Preorder[6] = {0,1,3,4,2,5};
    
    int Index = 0;
    int InStartIndex = 0;
    int InEndIndex = n;
    map<int,int> TreeNodeToIndex;
    createMapping(Inorder, TreeNodeToIndex, n);

    root = buildTree(Inorder, Preorder, Index, InStartIndex, InEndIndex, n, TreeNodeToIndex);
    //Answer should be 3 4 1 5 2 0.
    Postorder(root);

    cout<<endl;

    return 0;
}