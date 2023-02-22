#include<iostream>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

    TrieNode(char ch){
        this->data = ch;
        for(int i=0; i<26; i++){
            children[i] = nullptr;
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

        void insertUtil(TrieNode* root, string word){
            //Base case.
            if(word.length() == 0){
                root->isTerminal = true;
                return;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            //Character present.
            if(root->children[index] != nullptr){
                child = root->children[index];
            }
            else{
                //Character is absent.
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            //Recursive call.
            insertUtil(child, word.substr(1));
        }

        void insertWord(string word){
            insertUtil(root, word);
        }

        bool searchUtil(TrieNode* root, string word){
            //Base case.
            if(word.length() == 0){
                return root->isTerminal;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            //Character is present.
            if(root->children[index] != nullptr){
                child = root->children[index];
            }
            else{
                //Character is absent.
                return false;
            }

            //Recursion.
            return searchUtil(child, word.substr(1));
        }

        bool search(string word){
            return searchUtil(root, word);
        }

        //Without optimizing the memory.
        void removeUtil(TrieNode* root, string word){
            //Base case.
            if(word.length() == 0){
                root->isTerminal = false;
                return;
            }
            
            int index = word[0] - 'A';
            
            return removeUtil(root->children[index], word.substr(1));
        }

        void remove(string word){
            removeUtil(root, word);
        }
};

int main()
{
    Trie* t = new Trie();

    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");

    t->remove("DO");

    if(t->search("DO")){
        cout<<"Word is present"<<endl;
    }
    else{
        cout<<"Word is absent"<<endl;
    }

    return 0;
}