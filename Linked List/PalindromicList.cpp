//Given the linked list(LL) check whether the LL is palindrome or not.
/*
Algorithm : 
    1. Using string for storing the data and checking whether it is palindrome using two pointer approach. Time complexity : O(n), Space complexity : O(n).
    2. Finding mid and reversing linked list after it and traverse both list with head1 pointing to first list and head2 pointing 2 reversed lsit. Time complexity : O(n), Space complexity : O(1).
    3. Using Stack. Time complexity : O(n), Space complexity : O(n).
*/
#include<iostream>
#include<stack>
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
    head->next = insertion(head->next, tail = head);

    return head;
}

int findLen(ListNode* head){
    int count = 0;
    while(head != nullptr){
        count++;
        head = head->next;
    }
    return count;
}

//Approach : 3.
/* bool isPalindrome(ListNode* head){
    stack<int> st;
    int length = findLen(head);
    int mid = length/2;
    int count = 0;

    while(count < mid){
        count++;
        st.push(head->data);
        head = head->next;
    }
    //Length is odd then ignore middle element.
    if(length%2 != 0){
        count++;
        head = head->next;
    }

    while(count < length && head != nullptr){
        int element = st.top();
        st.pop();

        if(head->data != element){
            return false;
        }
        count++;
        head = head->next;
    }
    return true;
} */

//Approach : 1.
/* bool isPalindrome(ListNode* head){
    string s;
    while(head != nullptr){
        s += char(head->data);
        head = head->next;
    }
    int i = 0;
    int j = s.length()-1;

    while(i < j){
        if(s[i++] != s[j--]){
            return false;
        }
    }
    return true;
} */

//Approach : 2.
ListNode* findMid(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head->next;

    while(fast != nullptr){
        fast = fast->next;
        if(fast != nullptr){
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

ListNode* reverse(ListNode* temp){
    //Base case.
    if(temp == nullptr || temp->next == nullptr){
        return temp;
    }
    ListNode* rest = reverse(temp->next);
    temp->next->next = temp;
    temp->next = nullptr;
    return rest;
}

bool isPalindrome(ListNode* head){
    ListNode* mid = findMid(head);
    ListNode* temp = mid->next;

    mid->next = reverse(temp);

    ListNode* head1 = head;
    ListNode* head2 = mid->next;

    while(head2 != nullptr){
        if(head1->data != head2->data){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
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
    ListNode* tail = nullptr;

    head = insertion(head, tail);

    printing(head);

    if(isPalindrome(head)){
        cout<<"Linked List is palindrome"<<endl;
    }
    else{
        cout<<"Linked List is not palindrome"<<endl;
    }

    return 0;
}