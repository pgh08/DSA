// Given the string of unique characters and their respective frequencies in an array generate the Huffman encoding tree for it.
// Traverse Huffman encoding tree in preorder and print the same.
#include<iostream>
#include<vector>
#include<queue>

#define ti TreeNode

using namespace std;

class ti{
    public:
        int data;
        ti *left, *right;
    
    ti(int val){
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class compare{
    public:
        bool operator()(ti* a, ti* b){
            return a->data > b->data;
        }
};

void preorder(ti* root, string temp, vector<string> &ans){
    // Base Case.
    if(root->left == nullptr && root->right == nullptr){
        ans.push_back(temp);
        return;
    }

    preorder(root->left, temp+'0', ans);
    preorder(root->right, temp+'1', ans);
}

void solve(vector<int> &freq, vector<string> &ans){
    priority_queue<ti*, vector<ti*>, compare> pq;
    int n = freq.size();

    for(int i=0; i<n; i++){
        pq.push(new ti(freq[i]));
    }

    while(pq.size() > 1){
        ti* left = pq.top();
        pq.pop();

        ti* right = pq.top();
        pq.pop();

        ti* sumNode = new ti(left->data + right->data);
        sumNode->left = left;
        sumNode->right = right;

        pq.push(sumNode);
    }

    ti* root = pq.top();
    pq.pop();

    preorder(root, "", ans);
}


int main()
{
    string s;
    cout<<"Enter the value of the string"<<endl;
    cin>>s; // abcdef.

    int n = s.length();

    vector<int> freq(n, 0);
    cout<<"Enter the respective frequencies for the above character"<<endl;
    for(int i=0; i<n; i++){
        cin>>freq[i]; // 5 9 12 13 16 45.
    }

    vector<string> ans;

    // Huffman Encoding.
    solve(freq, ans);

    for(int i=0; i<n; i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}