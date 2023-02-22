#include<iostream>
#include<map>
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

bool detectLoop(Node* head){
    if(head == NULL){
        return false;
    }
    /* Node* temp = head;
    map<Node*, bool> visited;
    while(temp != NULL){
        if(visited[temp] == true){
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false; */
    Node* fast = head;
    Node* slow = head;
    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
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

    printing(head);

    tail->next = head->next;
    cout<<endl;
    if(detectLoop(head)){
        cout<<"Loop is Present"<<endl;
    }
    else{
        cout<<"Loop is not Present"<<endl;
    }
    
    return 0;
}