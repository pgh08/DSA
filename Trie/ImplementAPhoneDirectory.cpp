//Given a vector of contact list and query string find all the suggestions given in a particular query string search.
/*
Algorithm :
    1. Using Trie :
        --> Insert all the elements of the contact list into trie. Time complexity : O(n), Space complexity : O(m*n).
        --> For each last character entered compute resulting suggestion. Time Complexity : O(x1*n), Space complexity : O(n*x2).
        --> For computing resulting suggestion use recursion (Exclude and include game) with backtracking. Time Complexity : x1 = O(26*m^2), Space complexity : x2 = O(m).
        --> Overall Time and Space Complexity is given by : Time Complexity : O(n*m^2), Space Complexity : O(n*m).
*/
#include<iostream>
#include<vector>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

    TrieNode(char ch){
        this->data = ch;
        for(int i=0; i<26; i++){
            children[26] = NULL;
        }
        this->isTerminal = false;
    }
};

class Trie{
    public:
        TrieNode* root;

        Trie(){
            root = new TrieNode('\0');
        }

        void insert(TrieNode* root, string word){
            if(word.length() == 0){
                root->isTerminal = true;
                return;
            }
            int index = word[0] - 'a';
            TrieNode* child;

            //Character is present.
            if(root->children[index] != NULL){
                child = root->children[index];
            }
            else{
                //Character is absent.
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            //Recursive call.
            insert(child, word.substr(1));
        }
        
        void insertWord(string word){
            insert(root, word);
        }

        void printSuggestions(TrieNode* curr, vector<string> &temp, string prefix){
            //Base case.
            if(curr->isTerminal){
                temp.push_back(prefix);
            }

            for(char ch='a'; ch<='z'; ch++){
                TrieNode* next = curr->children[ch - 'a'];

                if(next != NULL){
                    prefix.push_back(ch);
                    printSuggestions(next, temp, prefix);
                    prefix.pop_back();
                }
            }
        }

        void getSuggestions(string queryString, vector<vector<string>> &ans){
            TrieNode* prev = root;
            string prefix = "";

            for(int i=0; i<queryString.size(); i++){
                //Adding last element of search to the string.
                char lastChar = queryString[i];
                prefix.push_back(lastChar);

                //Assigning curr node and if curr node is NULL come out of the loop.
                TrieNode* curr = prev->children[lastChar - 'a'];

                if(curr == NULL){
                    break;
                }

                //Creating temp for pushing suggestion for current last character.
                vector<string> temp;
                printSuggestions(curr, temp, prefix);

                ans.push_back(temp);
                temp.clear();
                prev = curr;
            }
        }
};

int main()
{   
    int n;
    cout<<"Enter the number of contact list"<<endl;
    cin>>n;

    vector<string> contactList(n);

    string queryString;
    
    //Taking input.
    cout<<"Enter the contact list"<<endl;
    for(int i=0; i<n; i++){
        cin>>contactList[i];
    }

    cout<<"Enter the query string"<<endl;
    cin>>queryString;

    Trie *t = new Trie();

    //Inserting contactList into the Trie.
    for(int i=0; i<contactList.size(); i++){
        t->insertWord(contactList[i]);
    }

    vector<vector<string>> ans;

    t->getSuggestions(queryString, ans);

    cout<<"Suggestions are : "<<endl;

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}