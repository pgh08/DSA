#include<iostream>
#include<vector>
#include<unordered_map>
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

TreeNode* buildTree(TreeNode* root){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    root = new TreeNode(data);

    if(data == -1){
        return nullptr;
    }

    cout<<"Enter the data for left of "<<root->data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for right of "<<root->data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void createMapping(vector<int> &Inorder, int n, unordered_map<int,int> &inorderValueToIndex){
    for(int i=0; i<n; i++){
        inorderValueToIndex[Inorder[i]] = i;
    }
}

TreeNode* buildFromInorderPreorder(TreeNode* root, vector<int> &Inorder, vector<int> &Preoder, unordered_map<int,int> &inorderValueToIndex, int &preoderIndex, int inoderIndexStart, 
int inorderIndexEnd, int n){
    // Base Case.
    if(preoderIndex >= n || inoderIndexStart > inorderIndexEnd){
        return nullptr;
    }

    int element = Preoder[preoderIndex++];
    
    root = new TreeNode(element);

    int pos = inorderValueToIndex[element];
    
    root->left = buildFromInorderPreorder(root->left, Inorder, Preoder, inorderValueToIndex, preoderIndex, inoderIndexStart, pos-1, n);
    root->right = buildFromInorderPreorder(root->right, Inorder, Preoder, inorderValueToIndex, preoderIndex, pos+1, inorderIndexEnd, n);

    return root;
}

void Postorder(TreeNode* root){
    // Base Case.
    if(root == nullptr){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    int n;
    cout<<"Enter the size of the vector"<<endl;
    cin>>n;

    vector<int> Inorder(n), Preorder(n);
    cout<<"Enter the data for Inorder Array"<<endl;

    for(int i=0; i<n; i++){
        cin>>Inorder[i];
    }

    cout<<"Enter the data for Preorder Array"<<endl;

    for(int i=0; i<n; i++){
        cin>>Preorder[i];
    }

    TreeNode* root = nullptr;
    // root = buildTree(root);

    int preoderIndex = 0;
    int inorderIndexStart = 0, inorderIndexEnd = n;

    unordered_map<int,int> inorderValueToIndex;
    createMapping(Inorder, n, inorderValueToIndex);
    
    root = buildFromInorderPreorder(root, Inorder, Preorder, inorderValueToIndex, preoderIndex, inorderIndexStart, inorderIndexEnd, n);

    Postorder(root);

    return 0;
}