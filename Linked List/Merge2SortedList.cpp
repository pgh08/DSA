#include<bits/stdc++.h>
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
    if(head == NULL){
        head = new Node(d);
        return;
    }
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

Node* merging(Node* head1, Node* head2){
    Node* ans = NULL;
    if(head1 == NULL && head2 == NULL){
        return NULL;
    }
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            insert(ans, head1->data);
            head1 = head1->next;
        }
        else{
            insert(ans, head2->data);
            head2 = head2->next;
        }
    }
    //If head 1 is not NULL.
    while(head1 != NULL){
        insert(ans, head1->data);
        head1 = head1->next;
    }
    //If head 2 is not NULL.
    while(head2 != NULL){
        insert(ans, head2->data);
        head2 = head2->next;
    }
    return ans;
}

void reversing(Node* &head){
    if(head == NULL){
        return;
    }
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void printing(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main()
{
    Node* head1 = new Node(80);
    insert(head1, 60);
    insert(head1, 40);
    insert(head1, 20);
    insert(head1, 0);

    Node* head2 = new Node(70);
    insert(head2, 50);
    insert(head2, 30);
    insert(head2, 10);

    cout<<"Before merging"<<endl;
    printing(head1);
    printing(head2);

    cout<<"After merging"<<endl;
    Node* result = merging(head1, head2);
    reversing(result);
    printing(result);

    return 0;
}