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

ListNode* insert(ListNode* head){
    int value;
    cout<<"Enter the data"<<endl;
    cin>>value;
    head = new ListNode(value);

    if(value == -1){
        return nullptr;
    }
    head->next = insert(head->next);
    return head;
}

ListNode* findMiddle(ListNode* head){
    if(head == nullptr){
        return head;
    }
    ListNode* fastNode = head->next;
    ListNode* slowNode = head;

    while(fastNode != nullptr && fastNode->next != nullptr){
        fastNode = fastNode->next->next;
        slowNode = slowNode->next;
    }
    return slowNode;
}

ListNode* mergeList(ListNode* firstNode, ListNode* secondNode){
    //Base Case.
    if(firstNode == nullptr){
        return secondNode;
    }
    if(secondNode == nullptr){
        return firstNode;
    }

    ListNode* res = nullptr;

    if(firstNode->data <= secondNode->data){
        res = firstNode;
        
        //Recursive Call.
        res->next = mergeList(firstNode->next, secondNode);
    }
    else{
        res = secondNode;

        //Recursive Call.
        res->next = mergeList(firstNode, secondNode->next);
    }
    return res;
}

ListNode* mergeSortList(ListNode* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }

    ListNode* mid = findMiddle(head);
    //Making Next Element of middle as new head (Splitting the given List).
    ListNode* head2 = mid->next;
    mid->next = nullptr;

    //Sorted insert of splitted List.
    ListNode* left = mergeSortList(head);
    ListNode* right = mergeSortList(head2);

    ListNode* finalHead = mergeList(left, right);

    return finalHead; 
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

    head = insert(head);

    cout<<"Linked List before sorting"<<endl;
    print(head);

    head = mergeSortList(head);

    cout<<"Linked List before sorting"<<endl;
    print(head);

    return 0;
}