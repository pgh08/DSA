#include<iostream>
using namespace std;

class Stack{
    public:
        int top;
        int size;
        int *arr;
    Stack(int len){
        this->size = len;
        top = -1;
        arr = new int[size];
    }

    void push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop(){
        if(top >= 0){
            top--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }

    int peek(){
        if(top >= 0){
            return arr[top];
        }
        else{
            cout<<"Empty"<<endl;
            return -1;
        }
    }

    bool isempty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};



int main()
{
    Stack s(5);
    s.push(22);
    s.push(33);
    s.push(44);

    cout<<"Top of the stack is : "<<s.peek()<<endl;
    s.pop();
    cout<<"Top of the stack is : "<<s.peek()<<endl;
    s.pop();
    cout<<"Top of the stack is : "<<s.peek()<<endl;
    s.pop();
    /* cout<<"Top of the stack is : "<<s.peek()<<endl; */

    if(s.isempty()){
        cout<<"Stack is Empty"<<endl;
    }
    else{
        cout<<"Stack is not Empty"<<endl;
    }

    return 0;
}