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

Node* reverse(Node* head, int k){
    //Base case.
    if(head == NULL){
        return NULL;
    }
    //Normal reverse operation.
    Node* next = NULL;
    Node* prev = NULL;
    Node* curr = head;
    int count = 0;
    while(curr != NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    //Recursive call.
    if(next != NULL){
        head->next = reverse(next, k);
    }
    return prev;
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
    Node* head = new Node(60);
    insertAtFirst(head, 50); 
    insertAtFirst(head, 40); 
    insertAtFirst(head, 30); 
    insertAtFirst(head, 20); 
    insertAtFirst(head, 10); 

    printing(head);
    cout<<endl;
    Node* ans = reverse(head, 4);
    printing(ans);
    cout<<endl;

    return 0;

}