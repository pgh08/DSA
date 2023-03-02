#include<iostream>
using namespace std;

class TwoStack{
    public:
        int size;
        int top1;
        int top2;
        int *arr;

    TwoStack(int s){
        this->size = s;
        this->top1 = -1;
        this->top2 = size;
        this->arr = new int[s];
    }

    void push1(int data){
        if(top2 - top1 > 1){
            top1++;
            arr[top1] = data;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    void push2(int data){
        if(top2 - top1 > 1){
            top2--;
            arr[top2] = data;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    int pop1(){
        if(top1 >= 0){
            int top = arr[top1];
            top1--;
            return top;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
        return -1;
    }

    int pop2(){
        if(top2 < size){
            int top = arr[top2];
            top2++;
            return top;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
        return -1;
    }

    bool isEmpty(){
        if(top1 == -1 && top2 == size){
            return true;
        }
        return false;
    }
};

int main()
{
    TwoStack ts(5);

    if(ts.isEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }

    ts.push1(10);
    ts.push1(9);
    ts.push2(8);
    ts.push2(7);
    ts.push2(6);
    ts.push1(5);

    cout<<ts.pop1()<<" "<<ts.pop2()<<endl;
    ts.pop1();
    ts.pop1();
    ts.pop2();
    ts.pop2();
    ts.pop2();

    return 0;
}