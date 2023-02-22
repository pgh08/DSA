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

void insert(Node* &head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

Node* floydsalgo(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
        if(slow == fast){
            return slow;
        }
    }
    return NULL;
}

Node* startingLink(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* intersection = floydsalgo(head);
    Node* slow = head;
    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

void removeLoop(Node* head){
    if(head == NULL){
        return;
    }
    Node* begining = startingLink(head);
    Node* temp = begining;
    while(temp->next != begining){
        temp = temp->next;
    }
    temp->next = NULL;
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
    Node* tail = head;
    insert(head, 40);
    insert(head, 30);
    insert(head, 20);
    insert(head, 10);
    
    tail->next = head->next;

    Node* ans = startingLink(head);

    cout<<"Starting of Loop is "<<ans->data<<endl;

    removeLoop(head);
    cout<<"Loop is removed"<<endl;
    printing(head);

    return 0;    
}