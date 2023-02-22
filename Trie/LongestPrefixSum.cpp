//Given a array of strings find the longest common prefix.
/*
Algorithm :
    1. Brute force : 
        -->Pick a character from the first string in an array and compare it with all the strings same index character.
        -->Time Complexity : O(m*n), Space Complexity : O(1).

    2. Using Trie : 
        -->Build the trie using the given string array and mark terminal nodes.
        -->If any node has more than 1 childs then stop the childcount and return the ans.
        -->Time Complexity : O(n), Space Complexity : O(m).
*/
#include<iostream>
#include<vector>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        int childCount;

    TrieNode(char ch){
        this->data = ch;
        for(int i=0; i<26; i++){
            children[i] = nullptr;
        }
        this->isTerminal = false;
        this->childCount = 0;
    }
};

class Trie{
    public:
        TrieNode* root;
        
        Trie(char ch){
            root = new TrieNode(ch);
        }

        void insertWord(TrieNode* root, string word){
            //Base case.
            if(word.length() == 0){
                root->isTerminal = true;
                return;
            }

            int index = word[0] - 'a';
            TrieNode* child;

            //Character present.
            if(root->children[index] != nullptr){
                child = root->children[index];
            }
            else{
                //Character absent.
                child = new TrieNode(word[0]);
                root->childCount++;
                root->children[index] = child;
            }

            //Recursive call.
            insertWord(child, word.substr(1));
        }

        void insert(string word){
            insertWord(root, word);
        }

        void findLongestCommonPrefix(string str, string &ans){
            int size = str.length();

            for(int i=0; i<size; i++){
                char ch = str[i];

                if(root->childCount == 1){
                    ans += ch;

                    int index = ch - 'a';

                    root = root->children[index];
                }
                else{
                    break;
                }

                if(root->isTerminal == true){
                    break;
                }
            }
        }
};

void bruteForce(vector<string> &stringArray, int n, string &ans){
    for(int i=0; i<stringArray[0].length(); i++){
        char ch = stringArray[0][i];

        bool match = true;
        for(int j=1; j<n; j++){
            if((stringArray[j].length() < i) || (stringArray[j][i] != ch)){
                match = false;
                break;
            }
        }

        if(match == false){
            break;
        }
        else{
            ans += ch;
        }
    }
}

int main()
{
    int n;
    cout<<"Enter the number elements to be inserted in array"<<endl;
    cin>>n;
    vector<string> stringArray(n);

    for(int i=0; i<n; i++){
        cin>>stringArray[i];
    }

    Trie* t = new Trie('\0');

    for(int i=0; i<n; i++){
        t->insert(stringArray[i]);
    }

    string first = stringArray[0];
    string ans;

    //bruteForce(stringArray, n, ans);

    t->findLongestCommonPrefix(first, ans);

    cout<<"Longest Common Prefix is : "<<ans<<endl;

    return 0;
}