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

ListNode* insertData(ListNode* head, ListNode* &tail){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    head = new ListNode(data);

    if(data == -1){
        return nullptr;
    }

    head->next = insertData(head->next, tail = head);

    return head;
}

void print(ListNode* head){
    while(head != nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int getLen(ListNode* head){
    int count = 0;
    while(head != nullptr){
        count++;
        head = head->next;
    }

    return count;
}

ListNode* reverseInKGroups(ListNode* head, int len, int k){
    ListNode* curr = head;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;

    int count = 0;

    while(curr != nullptr && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    //Recursive call.
    if(next != nullptr && (len-k) >= k){
        head->next = reverseInKGroups(next, len-k, k);
    }
    else if((len-k) < k){
        head->next = next;
    }

    return prev;
}

int main()
{
    ListNode* head = nullptr;
    ListNode* tail = head;

    head = insertData(head, tail);

    cout<<"Before Reversing in K groups"<<endl;
    print(head);

    int k;
    cout<<"Enter the group in which you want to reverse"<<endl;
    cin>>k;

    int len = getLen(head);

    ListNode* ans = reverseInKGroups(head, len, k);

    cout<<"After reversing in K groups"<<endl;
    print(ans);

    return 0;
}