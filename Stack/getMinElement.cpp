#include<bits/stdc++.h>
using namespace std;

class Stack{
    private:
        int mini;
        stack<int> s;

    public:
        void push(int data){
            if(s.empty()){
                s.push(data);
                mini = data;
            }
            else{
                if(data < mini){
                    int value = 2*data-mini;
                    s.push(value);
                    mini = data;
                }
                else{
                    s.push(data);
                }
            }
        }

        int pop(){
            if(s.empty()){
                return -1;
            }
            int curr = s.top();
            s.pop();
            int prevmini;
            if(curr > mini){
                return curr;
            }
            else{
                prevmini = mini;
                int value = 2*mini-curr;
                mini = value;
                return prevmini;
            }
        }

        int top(){
            if(s.empty()){
                return -1;
            }
            int curr = s.top();
            if(curr > mini){
                return mini;
            }
            else{
                return curr;
            }
        }

        bool isEmpty(){
            return s.empty();
        }

        int getMin(){
            if(s.empty()){
                return -1;
            }
            return mini;
        }
};

int main()
{
    Stack s1;
    s1.push(2);
    s1.push(1);
    int ans = s1.pop();

    cout<<ans<<endl;

    return 0;
}