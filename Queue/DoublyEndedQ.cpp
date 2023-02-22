#include<bits/stdc++.h>
using namespace std;

class Doublyqueue{
    private:
        int *arr;
        int front;
        int rear;
        int size;
    public:
        Doublyqueue(int n){
            size = n;
            arr = new int[size];
            front = rear = -1;
        }

        void pushfront(int d){
            if(front == size-1){
                cout<<"Queue is full"<<endl;
                return;
            }
            else if(front == -1){
                front = rear = 0;
            }
            else if(front == 0){
                front = size-1;
            }
            else{
                front--;
            }
            arr[front] = d;
        }

        void pushrear(int d){
            if((rear == size-1 && front == 0) || (rear == (front-1)%(size-1) && front != 0)){
                cout<<"Queue is full"<<endl;
                return;
            }
            else if(front == -1){
                front = rear = 0;
            }
            else if(rear == size-1 && front != 0){
                rear = 0;
            }
            else{
                rear++;
            }
            arr[rear] = d;
        }

        int popfront(){
            if(front == -1){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            int ans = arr[front];
            //arr[front] = -1;
            if(front == rear){
                front = rear = -1;
            }
            else if(front == size-1){
                front = 0;
            }
            else{
                front++;
            }
            return ans;
        }

        int popback(){
            if(rear == -1){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            int ans = arr[rear];
            //arr[rear] = -1;
            if(front == rear){
                front = rear = -1;
            }
            else if(rear == 0){
                rear = size - 1;
            }
            else{
                rear--;
            }
            return ans;
        }
};

int main()
{
    Doublyqueue dq(5);
    dq.pushfront(1);
    dq.pushrear(2);
    dq.pushfront(3);
    dq.popback();
    dq.pushrear(4);
    dq.pushrear(5);

    cout<<dq.popfront()<<endl;
    cout<<dq.popback()<<endl;

    cout<<dq.popfront()<<endl;
    cout<<dq.popback()<<endl;

    cout<<dq.popfront()<<endl;
    cout<<dq.popback()<<endl; 

    return 0;
}