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

int main()
{
    Node* head = new Node(50);

    insertAtFirst(head, 40);
/*     insertAtFirst(head, 30); 
    insertAtFirst(head, 20); 
    insertAtFirst(head, 10); 
    insertAtFirst(head, 60); 
 */ 
    printing(head);
    cout<<endl;

    Node* slow = head;
    Node* fast = head->next;
    int count = 1;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            break;
        }
        slow = slow->next;
        count++;
    }
    cout<<"Middle element is "<<slow->data<<" at position "<<count<<endl;

    return 0;
}