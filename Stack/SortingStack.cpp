#include<bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &s, int num){
    //Base case.
    if(s.empty() || (!s.empty() && s.top() < num)){
        s.push(num);
        return;
    }
    int n = s.top();
    s.pop();
    //Recursive call.
    sortedInsert(s, num);
    s.push(n); 
}

void sortedStack(stack<int> &s){
    //Base case.
    if(s.empty()){
        return;
    }
    int num = s.top();
    s.pop();

    //Recursive call.
    sortedStack(s);

    sortedInsert(s, num);
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
    s.push(3423);
    s.push(21);
    s.push(1);
    s.push(12234);
    s.push(12);

    cout<<"Before Sorting"<<endl;
    printing(s);
    cout<<endl;

    cout<<"After Sorting"<<endl;
    sortedStack(s);
    printing(s);

    return 0;
}