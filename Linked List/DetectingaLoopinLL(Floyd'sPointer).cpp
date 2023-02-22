#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
    node(int d){
        this->data = d;
        this->next = NULL;
    }
};

void insertAtFirst(node* &head, int value){
    node* temp = new node(value);
    temp->next = head;
    head = temp;
}

bool loop(node* head){
    node* fast = head;
    node* slow = head;
    while(fast != NULL && fast != slow){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }
    if(fast == NULL){
        return false;
    }
    return true;
}

int main()
{
    node* head = new node(60);
    insertAtFirst(head, 50); 
    insertAtFirst(head, 40); 
    insertAtFirst(head, 30); 
    insertAtFirst(head, 20); 
    insertAtFirst(head, 10);

    if(loop(head)){
        cout<<"Loop is detected"<<endl;
    }
    else{
        cout<<"Loop is not detected"<<endl;
    }
    return 0;
}