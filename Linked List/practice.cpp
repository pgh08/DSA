#include<iostream>
using namespace std;

class ListNode{
    public:
        int data;
        ListNode* next;

    ListNode(int val){
        this->data = val;
        this->next = nullptr;
    }
};

ListNode* insert(ListNode* head){
    int value;
    cout<<"Enter the value of node"<<endl;
    cin>>value;
    head = new ListNode(value);

    if(value == -1){
        return nullptr;
    }

    head->next = insert(head->next);

    return head;
}

int getLen(ListNode* head){
    int count = 0;
    while(head){
        count++;
        head = head->next;
    }

    return count;
}

ListNode* reverse(ListNode* head){
    ListNode* curr = head;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void printing(ListNode* head){
    while(head != nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main()
{
    ListNode* head = nullptr;
    head = insert(head);

    int len = getLen(head);
    
    cout<<"Normal printing"<<endl;
    printing(head);

    ListNode* reversedNode = reverse(head);

    cout<<"Abnormal printing"<<endl;
    printing(head);

    return 0;
}