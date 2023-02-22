//Given a Linked List and size 'K', reverse Linked List in 'K' groups.
/*
Algorithm:
    1. Use normal reversing of linked list operation with 'k' size in while loop.
    2. use recursive call.
    3. If next not equal to null then connect head->next to return value of recursive function.
*/
#include<iostream>
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

ListNode* insertion(ListNode* head, ListNode* &tail){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;

    head = new ListNode(data);

    if(data == -1){
        return nullptr;
    }
    head->next = insertion(head->next, tail=head);

    return head;
}

void printing(ListNode* head){
    ListNode* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

ListNode* reverseInK(ListNode* head, int k){
    //Base case.
    if(head == nullptr){
        return nullptr;
    }
    int count = 0;
    ListNode* curr = head;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;

    while(curr != nullptr && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(next != nullptr){
        head->next = reverseInK(next, k);
    }
    return prev;
}

int main()
{
    ListNode* head = nullptr;
    ListNode* tail = head;
    head = insertion(head, tail);

    cout<<"Before reversing"<<endl;

    printing(head);

    int k;
    cout<<"Enter the value of k"<<endl;
    cin>>k;

    cout<<"After reversing in 'K' groups"<<endl;

    ListNode* res = reverseInK(head, k);

    printing(res);

    return 0;
}