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

void insertion(Node* &Head, int d){
    Node* temp = new Node(d);
    temp->next = Head;
    Head = temp;
}

void reverselist(Node* &Head){
    Node* curr = Head;
    Node* prev = NULL;
    Node* next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    Head = prev;
}

void reversebtwn(Node* &Head, int pos1, int pos2){
    int current1 = 1;
    Node* curr = Head;
    Node* start = Head;
    if(pos1 == pos2){
        return;
    }
    while(current1 < pos1){
        start = curr;
        curr = curr->next;
        current1++;
    }
    Node* prev = NULL;
    Node* next = NULL;
    while(current1 <= pos2){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        current1++;
    }
    curr = start->next;
    start->next = prev;
    curr->next = next;
}

void printing(Node* Head){
    Node* temp = Head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    Node* Head = new Node(10);

    insertion(Head, 20);
    insertion(Head, 30);
/*     insertion(Head, 40);
    insertion(Head, 50);
    insertion(Head, 60);
    insertion(Head, 70);
    insertion(Head, 80); */

    printing(Head);

    reverselist(Head);

    cout<<endl;

    printing(Head);

    reversebtwn(Head, 1, 2);

    cout<<endl;

    printing(Head);

return 0;
}