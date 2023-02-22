#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s, int n){
    //Base case.
    if(s.empty()){
        s.push(n);
        return;
    }
    int num = s.top();
    s.pop();
    //Recursive call.
    insertAtBottom(s, n);
    s.push(num);
}

int main()
{
    int n;
    cin>>n;
    stack<int> s;
    s.push(10);
    s.push(9);
    s.push(8);
    s.push(7);
    s.push(6);

    insertAtBottom(s, n);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;

}