#include<iostream>
using namespace std;

class Node{

public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        //Memory free.
        if(next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is Free "<<value<<endl;
    }
};

void InsertAtHead(Node* &Head, int d){
    Node* temp = new Node(d);
    temp->next = Head;
    Head = temp;
}

void InsertAtEnd(Node* &Tail, int d){
    Node* temp = new Node(d);
    Tail->next = temp;
    Tail = temp; 
}

void InsertAtKey(Node* &Head,Node* &Tail, int pos, int d){
    if(pos == 1){
        InsertAtHead(Head, d);
        return;
    }
    Node* temp = Head;
    Node* insert = new Node(d);
    int count = 1;
    while(count < pos-1){
        temp = temp->next;
        count++;
    }
    if(temp->next == NULL){
        InsertAtEnd(Tail, d);
        return;
    }
    insert->next = temp->next;
    temp->next = insert;
}

void deleteAtStart(Node* &Head){
    Node* temp = Head;
    Head = Head->next;
    temp->next = NULL;
    delete temp;    
}

/*void deleteAtEnd(Node* &Head,Node* &Tail){
    Node* temp = Head;
    while(temp != NULL){
        temp = temp->next;
    }
    delete temp;
}*/

void deleteAtPosition(Node* &Head, int pos, Node* &Tail){
    if(pos == 1){
        deleteAtStart(Head);
        return;
    }
    Node* temp = Head;
    int count = 1;
    Node* prev = NULL;
    while(count < pos){
        prev = temp;
        temp = temp->next;
        count++;
    }
    prev->next = temp->next;
    temp->next = NULL;
    delete temp;
}

void printing(Node* &Head){
    Node* temp = Head;
//Till temp becomes null.
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* node1 = new Node(10);

    //Head pointed to node1.
    Node* Head = node1;

    //Tail pointed to node1.
    Node* Tail = node1;

    InsertAtHead(Head, 12);

    InsertAtEnd(Tail, 15);
     
    InsertAtKey(Head, Tail, 4, 22);

    printing(Head);
//    deleteAtStart(Head);
    deleteAtPosition(Head, 4, Tail);
    printing(Head);
    cout<<"Head "<< Head->data<<endl;
    cout<<"Tail "<< Tail->data<<endl;
    return 0;
}