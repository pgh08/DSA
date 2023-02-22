#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s, int n){
    //Base case.
    if(s.empty()){
        s.push(n);
        return;
    }
    int num = s.top();
    s.pop();
    insertAtBottom(s, n);
    s.push(num);
}

void reversing(stack<int> &s){
    if(s.empty()){
        return;
    }
    int num = s.top();
    s.pop();
    //Recursive call.
    reversing(s);

    insertAtBottom(s, num);
}

void printing(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(9);
    s.push(8);
    s.push(7);
    s.push(6);

    cout<<"Before reversing"<<endl;
    printing(s);

    cout<<"After reversing"<<endl;
    reversing(s);
    printing(s);

    return 0;
}