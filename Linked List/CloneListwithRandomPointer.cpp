#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* random;
    
    Node(int d){
        this->data = d;
        this->next = NULL;
        this->random = NULL;
    }

    ~Node(){}
};
void truth(Node* head1, Node* head2);
void build(Node* &head, Node* &tail, int d){
    Node* temp = new Node(d);
    if(tail == NULL){
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

void printing(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void cloning(Node* head1){
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
    Node* temp = head1;
    while(temp != NULL){
        build(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }
    /*unordered_map<Node*,Node*> umap;
    Node* originalNode = head1;
    Node* cloneNode = cloneHead;

    while(originalNode != NULL){
        umap[originalNode] = cloneNode;
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }
    originalNode = head1;
    cloneNode = cloneHead;

    while(originalNode != NULL){
        cloneNode->random = umap[originalNode->random];
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    } */
    Node* originalNode = head1;
    Node* cloneNode = cloneHead;
    while(originalNode != NULL){
        Node* next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next;

        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next;
    }
    temp = head1;
    while(temp != NULL){
        if(temp->next != NULL){
            temp->next->random = temp->random? temp->random->next:temp->random;
        }
        temp = temp->next->next;
    }
    originalNode = head1;
    cloneNode = cloneHead;
    while(originalNode != NULL){
        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;
        if(originalNode != NULL){
            cloneNode->next = originalNode->next;
        }
        cloneNode = cloneNode->next;
    }
    printing(cloneHead);
    truth(head1, cloneHead);
}

void truth(Node* head1, Node* head2){
    while(head1 != NULL && head2 != NULL){
        if((head1->data != head2->data) || (head1->random->data != head2->random->data)){
            cout<<"Both list are not equal"<<endl;
            return;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    cout<<"Both list are equal"<<endl;
}

int main()
{
    Node* head = new Node(10);
    Node* tail = head;

    build(head, tail, 20);
    build(head, tail, 30);
    build(head, tail, 40);
    build(head, tail, 50);

    printing(head);

    Node* temp = head;
    temp->random = temp->next->next;
    temp->next->random = head;
    temp->next->next->next->random = temp->next->next;
    temp->next->next->random = tail;
    tail->random = temp->next;

    cloning(head);

    return 0;
}