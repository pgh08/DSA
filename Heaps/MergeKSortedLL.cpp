//Given an array of 'K' heads of the linked list which are sorted merge that to form sorted linked list.
/*
Algorithm :
    1. Brute force : 
        -->Push all the elements into newly created array. Time complexity : O(n*k), Space complexity : O(n*k).
        -->Sort the above array and copy elements from that array to form linked list So the overall Time complexity : O((n*k)log(n*k)), Space complexity : O(n*k).

    2. Using MinHeap : 
        -->Push all the heads present in the array to minheap. 
        -->Now remove till minHeaps size greater than zero run the loop.
        -->Assign top of minHeap to a variable and if that variables next element is not null push it into minHeap.
        -->If head is null push it assign the above variable to both head and tail else insert at tail.
        -->Time complexity : O((n*k)log(k)), Space complexity : O(k).
*/
#include<iostream>
#include<queue>
#include<vector>
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

class compare{
    public:
        bool operator()(ListNode* a, ListNode* b){
            return a->data > b->data;
        }
};

//Insertion (at tail) Linked List.
ListNode* insertAtTail(ListNode* head, ListNode* &tail){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;

    head = new ListNode(data);

    if(data == -1){
        return nullptr;
    }

    head->next = insertAtTail(head->next, tail=head);

    return head;
}

ListNode* mergeKsortedLL(vector<ListNode*> Klist, int size){
    //step 1 : Create a miHeap with custom compare function and push push K elements of the vector to the heap.
    priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

    for(int i=0; i<size; i++){
        if(Klist[i] != nullptr){
            minHeap.push(Klist[i]);
        }
    }

    //Step 2 : Create an ans ListNode and follow algorithm as mentioned in the begining.
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    while(minHeap.size() > 0){
        ListNode* top = minHeap.top();
        minHeap.pop();

        if(top->next != nullptr){
            minHeap.push(top->next);
        }

        if(head == nullptr){
            head = top;
            tail = head;
        }
        else{
            tail->next = top;
            tail = top;
        }
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
    int k;
    cout<<"Enter the number of linked list required"<<endl;
    cin>>k;

    //Creating K Linked Lists.
    vector<ListNode*> Klist(k);

    for(int i=0; i<k; i++){
        cout<<"Creating "<<i+1<<"th Linked List"<<endl;
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        head = insertAtTail(head, tail);

        Klist[i] = head;
    }

    //Printing K Linked List.
    for(int i=0; i<k; i++){
        cout<<"Printing "<<i+1<<"th Linked List"<<endl;
        printing(Klist[i]);
        cout<<endl;
    }

    //Basically size is equal to k.
    int size = Klist.size();
    ListNode* ansHead = nullptr;

    ansHead = mergeKsortedLL(Klist, size);

    //Printing merged Linked List.
    cout<<"Merged linked list is : "<<endl;
    printing(ansHead);

    return 0;
}