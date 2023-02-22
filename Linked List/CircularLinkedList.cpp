//Circular Singly Linked List.
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

    ~Node(){
        int value = this->data;
        while(next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory Freed "<<value<<endl; 
    }
};

void InsertNode(Node* &Tail, int d, int element){
    if(Tail == NULL){
        Node* newNode = new Node(d);
        Tail=newNode;
        newNode->next = newNode;
    }
    else{
        Node* curr = Tail;
        while(curr->data != element){
            curr = curr->next;
        }
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void printing(Node* Tail){
    Node* temp = Tail;
    if(Tail == NULL){
        cout<<"List is Empty"<<endl;
        return;
    }
    do {
        cout<<Tail->data<<" ";
        Tail = Tail->next;
    }while(Tail != temp);
    cout<<endl;
}

void deleteNode(Node* &Tail, int element){
    if(Tail->next == Tail){
        Tail->next = NULL;
        delete Tail;
    }
    else{
        Node* curr = Tail->next;
        Node* prev = Tail;
        while(curr->data != element){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        if(curr == prev){
            Tail = NULL;
            return;
        }
        else if(Tail == curr){
            Tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
//    Node* node1 = new Node(10);

//    Node* Head = node1;
    Node* Tail = NULL;

    InsertNode(Tail, 3, 5);
//    InsertNode(Tail, 4, 3);
//    InsertNode(Tail, 5, 4);
//    InsertNode(Tail, 10, 4);
//    printing(Tail);

//  Deleting Node.

    deleteNode(Tail, 3);
    printing(Tail);

    return 0;
}