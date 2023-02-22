#include<iostream>
using namespace std;

class Queue{
    private:
        int qfront;
        int qrear;
        int *arr;
        int size;
    public:
        Queue(int n){
            size = n;
            arr = new int[size];
            qfront = 0;
            qrear = 0;
        }

        bool isEmpty(){
            if(qfront == qrear){
                return true;
            }
            else{
                return false;
            }
        }

        void enqueue(int d){
            if(qrear == size){
                return;
            }
            else{
                arr[qrear] = d;
                qrear++;
            }
        }

        int dequeue(){
            int ans = arr[qfront];
            if(qfront == qrear){
                return -1;
            }
            else{
                arr[qfront] = -1;
                qfront++;
                if(qfront == qrear){
                    qfront = 0;
                    qrear = 0;
                }
            }
            return ans;
        }

        int front(){
            if(qfront == qrear){
                return -1;
            }
            else{
                return arr[qfront];
            }
        }

};

int main()
{
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.front()<<endl;

    return 0;
}