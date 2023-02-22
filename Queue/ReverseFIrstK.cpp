#include<bits/stdc++.h>
using namespace std;

void ReverseInK(queue<int> &q, int k){
    stack<int> s;
    
    for(int i=0; i<k; i++){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    int size = q.size()-k;
    while(size--){
        q.push(q.front());
        q.pop();
    }
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
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(20);
    q.push(10);
    int k;
    cout<<"Enter the value of K"<<endl;
    cin>>k;

    cout<<"Before Reversing in K groups "<<endl;
    printing(q);

    cout<<"After Revering in K groups "<<endl;
    ReverseInK(q, k);

    printing(q);

    return 0;
}