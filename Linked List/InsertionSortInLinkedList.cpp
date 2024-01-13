// Given a Linked List sort it using insertion sort.
// Time Complexity : O(n^2), Space Complexity : O(1).
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

ListNode* buildList(ListNode* head){
    int data;
    cout<<"Enter the value"<<endl;
    cin>>data;
    head = new ListNode(data);

    if(data == -1){
        return nullptr;
    }

    head->next = buildList(head->next);

    return head;
}

ListNode* doInsertionSort(ListNode* head){
    if(!head){
        return nullptr;
    }

    ListNode* curr = head->next;
    ListNode* prev = head;

    while(curr != nullptr){
        if(curr->data >= prev->data){
            prev = curr;
        }
        else{
            int value = curr->data;
            // Moving to next node by skipping current node.
            prev->next = curr->next;
            ListNode* newNode = new ListNode(value);

            // If skipped node's value is smaller than head of the Linked List, insert the node at the begining.
            if(value <= head->data){
                newNode->next = head;
                head = newNode;
            }
            else{
                // If skipped node's value lies between head and prev node.
                ListNode* start = head;

                while(start != prev && value > start->next->data){
                    start = start->next;
                }

                newNode->next = start->next;
                start->next = newNode;
            }
        }

        curr = curr->next;
    }

    return head;
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
    head = buildList(head); // 19 20 16 12 24 29 21 -1.

    cout<<"Before Insertion Sort"<<endl;
    printing(head);

    head = doInsertionSort(head);

    cout<<"After Insertion Sort"<<endl;
    printing(head);

    return 0;
}