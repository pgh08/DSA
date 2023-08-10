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

ListNode* findMid(ListNode* head){
    if(head == nullptr){
        return nullptr;
    }

    ListNode* fast = head->next;
    ListNode* slow = head;

    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

ListNode* merge(ListNode* head1, ListNode* head2){
    if(head1 == nullptr){
        return head2;
    }
    if(head2 == nullptr){
        return head1;
    }

    ListNode* res = nullptr;

    if(head1->data <= head2->data){
        res = head1;

        res->next = merge(head1->next, head2);
    }
    else{
        res = head2;

        res->next = merge(head1, head2->next);
    }

    return res;
}

ListNode* mergeSort(ListNode* head){
    // Base Case.
    if(head == nullptr || head->next == nullptr){
        return head;
    }

    ListNode* mid = findMid(head);
    ListNode* head2 = mid->next;
    mid->next = nullptr;

    ListNode* left = mergeSort(head);
    ListNode* right = mergeSort(head2);

    ListNode* finalHead = merge(left, right);

    return finalHead;
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

    cout<<"List before sorting"<<endl;
    printing(head);

    head = mergeSort(head);

    cout<<"List after sorting"<<endl;
    printing(head);

    return 0;
}