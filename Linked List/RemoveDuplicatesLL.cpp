#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next = NULL;

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

void removeDuplicate(Node* head){
    if(head == NULL){
        return;
    }
    Node* curr = head;
    while(curr != NULL){
        if((curr->next != NULL) && curr->data == curr->next->data){
            Node* nextofnext = curr->next->next;
            Node* nodetodelete = curr->next;
            delete (nodetodelete);
            curr->next = nextofnext;
        }
        else{
            curr = curr->next;
        }
    }
}

// For Unsorted Linked List.
/* void removeDuplicates(ListNode* &head){
    if(head == nullptr){
        return;
    }
    ListNode* curr = head;
    ListNode* prev = nullptr;
    set<int> s;
    while(curr != nullptr){
        if(s.find(curr->data) == s.end()){
            s.insert(curr->data);
            prev = curr;
        }
        else{
            prev->next = curr->next;
            delete curr;
        }
        curr = prev->next;
    }
} */

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
    insert(head, 4);
    insert(head, 4);
    insert(head, 3);
    insert(head, 2);
    insert(head, 2);
    insert(head, 1);
    cout<<"Before removing duplicates"<<endl;
    printing(head);
    cout<<endl;
    cout<<"After removing duplicates"<<endl;
    removeDuplicate(head);
    printing(head);
    cout<<endl;

    return 0;    
}