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

void insert(Node* &head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

Node* sorting(Node* head){
    int countZero = 0;
    int countOne = 0;
    int countTwo = 0;
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == 0){
            countZero++;
        }
        else if(temp->data == 1){
            countOne++;
        }
        else if(temp->data == 2){
            countTwo++;
        }
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        if(countZero != 0){
            temp->data = 0;
            countZero--;
        }
        else if(countOne != 0){
            temp->data = 1;
            countOne--;
        }
        else if(countTwo != 0){
            temp->data = 2;
            countTwo--;
        }
        temp = temp->next;
    }
    return head;
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
    Node* head = new Node(0);
    Node* tail = head;
    insert(head, 1);
    insert(head, 2);
    insert(head, 1);
    insert(head, 2);
    insert(head, 1);
    insert(head, 0);
    cout<<"Linked List before sorting"<<endl;
    printing(head);
    cout<<endl;
    cout<<"Linked List After sorting"<<endl;
    Node* ans = sorting(head);
    printing(ans);
    cout<<endl;
    
    return 0;
}

//Using dummy node.
/* #include<iostream>
using namespace std;

class ListNode{
    public:
        int data;
        ListNode* next;

    ListNode(int d){
        this->data = d;
        this->next = nullptr;
    }

    ~ListNode(){}
};

ListNode* insert(ListNode* head, ListNode* &tail){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    head = new ListNode(data);

    if(data == -1){
        return nullptr;
    }

    head->next = insert(head, tail=head);

    return head;
}

void print(ListNode* head){
    while(head != nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main()
{
    ListNode* head = nullptr;
    ListNode *tail = head;
    
    head = insert(head, tail);

    cout<<"Before sorting"<<endl;
    print(head);

    ListNode* dummyZeroHead = new ListNode(-1);
    ListNode* dummyOneHead = new ListNode(-1);
    ListNode* dummyTwoHead = new ListNode(-1);

    ListNode* zeroHead = dummyZeroHead;
    ListNode* oneHead = dummyOneHead;
    ListNode* twoHead = dummyTwoHead;

    while(head != nullptr){
        if(head->data == 0){
            zeroHead->next = head;
            zeroHead = zeroHead->next;
        }
        else if(head->data == 1){
            oneHead->next = head;
            oneHead = oneHead->next;
        }
        else{
            twoHead->next = head;
            twoHead = twoHead->next;
        }
        head = head->next;
    }

    zeroHead->next = dummyOneHead->next ? dummyOneHead->next : dummyTwoHead->next;
    oneHead->next = dummyTwoHead->next;
    twoHead->next = nullptr;

    ListNode* ansHead = zeroHead;

    delete dummyZeroHead;
    delete dummyOneHead;
    delete dummyTwoHead;

    print(ansHead);

    return 0;
} */