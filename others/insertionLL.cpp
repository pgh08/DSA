#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};
//For inserting new node in the begining of the list.
void insert_begin(Node** head_ref, int val)
{
    Node* new_node = new Node();
//Assign data to new node.
    new_node->data = val;
//Storing head nodes pointer address in new_node.
    new_node->next = (*head_ref);
//Making new_node as head node.
    (*head_ref) = new_node;
}
//For inserting new node in the specified position.
void inser_specified(Node* head_ref, int key, int val)
{
    if(head_ref == NULL){
        cout<<"The previous node cannnot be empty";
        return;
    }
    Node* new_node = new Node();
//Assign data to new node.
    new_node->data = val;
//Locating previous node.
    while (head_ref->data != key && head_ref->next != 0)
    {
        head_ref = head_ref->next;
    }
    new_node->next = head_ref->next;
    head_ref->next = new_node;
}
//For inserting at the end of the least.
void insert_end(Node** head_ref, int val)
{
    Node* new_node = new Node();
    Node* last_node = *head_ref;
//Assign data to new node.
    new_node->data = val;
//Assign NULL value to next address of new_node.
    new_node->next = NULL;
//Checking if their is no node present.
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
//Traversing till the last node.
    while (last_node->next != NULL){
        last_node = last_node->next;
    }
//Making new_node as last node.
    last_node->next = new_node;
    return;
}
//For print the Linked List.
void printlist(Node* n)
{
    while (n != NULL){
        cout<<n->data<<" ";
        n = n->next;
    }
}
//Driver code.
int main()
{
    Node* Head = NULL;
//Calling the function to insert at the end.
    insert_end(&Head,15);
//Calling the function to insert at the begining.
    insert_begin(&Head,10);
//Calling the function to insert at the begining.
    insert_begin(&Head,5);
//Calling the function to insert at the end.
    insert_end(&Head,25);
//Calling the function to insert at the specified place.
    inser_specified(Head,15,20);
//Calling the function to print the list.
    printlist(Head);
//Terminating Program.
    return 0;
}