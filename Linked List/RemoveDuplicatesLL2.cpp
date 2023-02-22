#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
        int data;
        Node* next;
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

void insert(Node* &head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

//Method 1 : Brute Force.
/* void remmoveDuplicates(Node* head){
    Node* curr = head;
    Node* temp;
    while(curr != NULL && curr->next != NULL){
        temp = curr;
        while(temp->next != NULL){
            if(temp->next->data == curr->data){
                Node* duplicate = temp->next;
                temp->next = temp->next->next;
                delete (duplicate);
            }
            else{
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
} */

//Method 2 : Using Hashset.
void remmoveDuplicates(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    unordered_set<int> duplicate;
    while(curr != NULL){
        //Checking data is present.
        if(duplicate.find(curr->data) == duplicate.end()){
            duplicate.insert(curr->data);
            prev = curr;
        }
        else{
            prev->next = curr->next;
            delete curr;
        }
        curr = prev->next;
    }
}

void printing(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    Node* head = new Node(5);
    Node* tail = head;
    insert(head, 3);
    insert(head, 2);
    insert(head, 3);
    insert(head, 2);
    insert(head, 4);
    insert(head, 1);
    cout<<"Linked List before removing duplicates"<<endl;
    printing(head);
    cout<<endl;

    cout<<"Linked List before removing duplicates"<<endl;
    remmoveDuplicates(head);
    printing(head);
    cout<<endl;

    return 0;
}