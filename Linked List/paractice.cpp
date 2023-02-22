#include<iostream>
#include<unordered_map>
using namespace std;

class ListNode{
    public:
        int data;
        ListNode* next;
        ListNode* random;

    ListNode(int d){
        this->data = d;
        this->next = nullptr;
        this->random = nullptr;
    }

    ~ListNode(){}
};

ListNode* insertData(ListNode* head){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    head = new ListNode(data);

    if(data == -1){
        return nullptr;
    }

    head->next = insertData(head->next);

    return head;
}

void insertAtTail(ListNode* &cloneHead, ListNode* &cloneTail, int data){
    if(cloneHead == nullptr){
        cloneHead = new ListNode(data);
        cloneTail = cloneHead;
        return;
    }
    ListNode* temp = new ListNode(data);
    cloneTail->next = temp;
    cloneTail = temp;   
}

ListNode* cloneList(ListNode* head1){
    ListNode* cloneHead = nullptr;
    ListNode* cloneTail = nullptr;
    ListNode* temp = head1;

    //Creating List without random pointer.
    while(temp != nullptr){
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }
    unordered_map<ListNode*,ListNode*> nodeToRandomNode;
    ListNode* originalNode = head1;
    ListNode* cloneNode = cloneHead;
    
    // while(originalNode != nullptr){
    //     nodeToRandomNode[originalNode] = cloneNode;
    //     originalNode = originalNode->next;
    //     cloneNode = cloneNode->next;
    // }
    // originalNode = head1;
    // cloneNode = cloneHead;

    // while(originalNode != nullptr){
    //     cloneNode->random = nodeToRandomNode[originalNode->random];
    //     cloneNode = cloneNode->next;
    //     originalNode = originalNode->next;
    // }

    while(originalNode != nullptr){
        ListNode* next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next;

        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next;
    }

    ListNode* temp1 = head1;
    while(temp1 != nullptr){
        if(temp1->next != nullptr){
            temp1->next->random = temp1->random ? temp1->random->next : temp1->random;
        }
        temp1 = temp1->next->next;
    }
    originalNode = head1;
    cloneNode = cloneHead;

    while(originalNode != nullptr){
        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;
        if(originalNode != nullptr){
            cloneNode->next = originalNode->next;
        }
        cloneNode = cloneNode->next;
    }
    return cloneHead;
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

    // 1 2 3 4  5 6 7 8 9 10.

    head = insertData(head);

    print(head);

    head->random = head->next->next;
    head->next->random = head->next->next->next;
    head->next->next->random = head->next;

    ListNode* ans = cloneList(head);

    print(ans);

    return 0;
}