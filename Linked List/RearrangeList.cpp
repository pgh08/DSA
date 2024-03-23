// Given the linked list L1,L2, ....., Ln, rearrange the list so that linked list in the order L1,Ln,L2,Ln-1,....
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
    int val;
    cout<<"Enter the value of the node"<<endl;
    cin>>val;
    head = new ListNode(val);

    if(val == -1){
        return nullptr;
    }

    head->next = insert(head->next);

    return head;
}

ListNode* getMid(ListNode* head){
    ListNode* fast = head;
    ListNode* slow = head;

    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

ListNode* reverse(ListNode* head){
    // Base Case.
    if(head == nullptr || head->next == nullptr){
        return head;
    }

    ListNode* rest = reverse(head->next);
    head->next->next = head;

    head->next = nullptr;

    return rest;
}

void printing(ListNode* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }

    cout<<endl;
}

int main()
{
    ListNode* head = nullptr;
    head = insert(head);

    cout<<"Linked List before rearranging"<<endl;
    printing(head);

    cout<<"Linked List after rearranging"<<endl;
    if(head->next == nullptr){
        printing(head);
        return 0;
    }

    // Step1 : Find Mid.
    ListNode* mid = getMid(head);
    ListNode* temp = mid->next;
    mid->next = nullptr;

    // Step2 : Reverse Second half of the list.
    ListNode* second = reverse(temp);

    // Step3 : Traverse through first half by interlinking second half.
    ListNode* first = head;
    
    while(first != nullptr && second != nullptr){
        ListNode* next = first->next;
        first->next = second;
        first = next;

        next = second->next;
        second->next = first;
        second = next;
    }

    printing(head);

    return 0;
}