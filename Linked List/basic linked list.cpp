#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

int main()
{
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
//Creating new nodes.
    head = new Node();
    second = new Node();
    third = new Node();
//Connecting link between head node and second node.
    head->data = 1;
    head->next = second;
//Connecting link between second node and third node.
    second->data = 2;
    second->next = third;
//Assigning third node link to NULL.
    third->data = 3;
    third->next = NULL;
//Printing the data content of the list.
    while (head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    return 0;
}