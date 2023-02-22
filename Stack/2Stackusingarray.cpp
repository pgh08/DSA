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
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    void push1(int num){
        if(top2 - top1 > 1){    
            top1++;
            arr[top1] = num;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    void push2(int num){
        if(top2 - top1 > 1){
            top2--;
            arr[top2] = num;
        }
        else{
            cout<<"Stcak Overflow"<<endl;
        }
    }

    int pop1(){
        if(top1 >= 0){
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else{
            return -1;
        }
    }

    int pop2(){
        if(top2 < size){
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else{
            return -1;
        }
    }

    bool isEmpty(){
        if(top1 == -1 || top2 == size){
            return true;
        }
        return false;
    }
};

int main()
{
    TwoStack ts(6);

    ts.push1(10);
    ts.push1(8);

    ts.push2(1);
    ts.push2(3);
    ts.push2(5);
    ts.push2(7);

    ts.push1(100);

    cout<<ts.pop2()<<endl;

    ts.push1(6);


    return 0;
}