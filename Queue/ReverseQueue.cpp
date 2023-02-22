#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void ReverseUsingStack(queue<int> &q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

void recursiveReverse(queue<int> &q){
    if(q.empty()){
        return;
    }
    int data = q.front();
    q.pop();
    recursiveReverse(q);
    q.push(data);
}

void printing(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main()
{
    queue<int> q;
    q.push(50);
    q.push(40);
    q.push(30);
    q.push(20);
    q.push(10);
    cout<<"Before Reversing Queue : "<<endl;
    printing(q);

    //ReverseUsingStack(q);
    recursiveReverse(q);

    cout<<"After Reversing Queue : "<<endl;
    printing(q);

    return 0;
}