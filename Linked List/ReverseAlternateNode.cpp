#include<iostream>
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

Node* Insertion(Node* head){
    int value;
    cin>>value;
    head = new Node(value);

    if(value == -1){
        return NULL;
    }

    head->next = Insertion(head->next);

    return head;
}

void rearrange(struct Node *odd){
    //add code here.
    Node* originalHead = odd;
    Node* prev = NULL;
    
    // Step 1 : Extracting alternate nodes.
    Node* alternateHead = new Node(-1);
    Node* alternate = alternateHead;
    
    while(odd != NULL && odd->next != NULL){
        prev = odd;
        odd = odd->next;
        alternate = alternate->next;
        
        prev->next = odd->next;
        odd->next = NULL;
        odd = prev->next;
    }        
    
    // Step 2 : Reversing the extracted nodes.
    Node* curr = alternateHead->next;
    prev = NULL;
    Node* next = NULL;
    
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    alternateHead = prev;
    // Step 3 : Appending reversed List to original List.
    curr = originalHead;
    prev = NULL;
    
    while(curr != NULL){
        prev = curr;
        curr = curr->next;
    }
    
    while(alternateHead != NULL){
        prev->next = alternateHead;
        alternateHead = alternateHead->next;
        prev = prev->next;
    }
}

int main()
{
    Node* head = NULL;
    head = Insertion(head);// 10 4 9 1 3 5 9 4.

    rearrange(head);

    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;

    return 0;
}