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

void insertAtFirst(Node* &head, int value){
    Node* temp = new Node(value);
    temp->next = head;
    head = temp;
}

void printing(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* reverse(Node* head){
    //Base case.
    if(head == NULL || head->next == NULL){
        return head;
    }
    //Recursive call.
    Node* rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

int main()
{
    Node* head = new Node(60);
    insertAtFirst(head, 50); 
    insertAtFirst(head, 40); 
    insertAtFirst(head, 30); 
    insertAtFirst(head, 20); 
    insertAtFirst(head, 10);

    printing(head);
    cout<<endl;
    Node* ans = reverse(head);
    printing(ans);
    cout<<endl;

    return 0;
}