#include<iostream>
using namespace std;

class Node{

public:
    int data;
    Node* next;
    Node* prev;
    
    //Constructor.

    Node(int d){
        data = d;
        next = NULL;
        prev = NULL;
    }

    //Destructor.

    ~Node(){
        int value = this->data;
        while (next != NULL)
        {
            delete next;
            delete prev;
            this->next = NULL;
            this->prev = NULL;
        }
        cout<<"Memory freed "<<value<<endl;
    }
};

void printing(Node* &Head){
    Node* temp = Head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int getLength(Node* &Head){
    int len = 0;
    Node* temp = Head;

    while (temp != 0)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void InsertAtStart(Node* &Head, int d){
    Node* temp = new Node(d);
    temp->next = Head;
    Head->prev = temp;
    Head = temp;
}

void InsertAtEnd(Node* &Tail, int d){
    Node* temp = new Node(d);
    Tail->next = temp;
    temp->prev = Tail;
    Tail = temp;
}

void InsertAtPosition(Node* &Head,Node* &Tail, int pos, int d){
    if(pos == 1){
        InsertAtStart(Head, d);
        return;
    }
    Node* temp = Head;
    int count = 1;
    while (count < pos-1)
    {
        count++;
        temp = temp->next;
    }
    if(temp->next == NULL){
        InsertAtEnd(Tail, d);
        return;
    }
    Node* insert = new Node(d);
    insert->next = temp->next;
    temp->next->prev = insert;
    insert->prev = temp;
    temp->next = insert;
    
}

void deleteAtPosition(Node* &Head, Node* &Tail, int pos){
    if(pos == 1){
        Node* temp = Head;
        Head = Head->next;
        temp->next = NULL;
        Head->prev = NULL;
        delete temp;
    }
    else{
        Node* temp = Head;
        int count = 1;
        Node* pre = NULL;
        while(count < pos){
            count++;
            pre = temp;
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            pre->next = NULL;
            delete temp;
        }
        else{
            pre->next = temp->next;
            temp->next->prev = pre;
            temp->next = NULL;
            temp->prev = NULL;
            delete temp;
        }
    }
}

int main()
{
    Node* node1 = new Node(10);
    Node* Head = node1;
    Node* Tail = node1;
    
//Inserting.

    InsertAtStart(Head, 11);
    InsertAtStart(Head, 12);   
    InsertAtEnd(Tail, 8);
    InsertAtPosition(Head, Tail, 4, 9);
    InsertAtEnd(Tail, 7);
    InsertAtEnd(Tail, 6);
    InsertAtPosition(Head, Tail, 8, 5);
    printing(Head);

//Deleting. 

    deleteAtPosition(Head, Tail, 1);
    deleteAtPosition(Head, Tail, 4);
    deleteAtPosition(Head, Tail, 6);
    printing(Head); 

} 