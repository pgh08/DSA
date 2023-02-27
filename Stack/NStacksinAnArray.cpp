#include<bits/stdc++.h>
using namespace std;

class Stack{
    private:
        int *arr;
        int *top;
        int *next;
        int freespot;
        int n, size;

    public:
        Stack(int N, int S){
            n = N;
            size = S;
            arr = new int[size];
            top = new int[n];
            freespot = 0;
            next = new int[size];

            for(int i=0; i<n; i++){
                top[i] = -1;
            }

            for(int i=0; i<size; i++){
                next[i] = i+1;
            }
            next[size-1] = -1;
        }

        bool push(int x, int m){
            //Check whether stackover.
            if(freespot == -1){
                return false;
            }
            
            int index = freespot;

            //Update freespot.
            freespot = next[index];

            //Insert element into array.
            arr[index] = x;

            //Update next.
            next[index] = top[m-1];

            //Update top.
            top[m-1] = index;

            return true;
        }

        int pop(int m){
            //Checking underflow condition.
            if(top[m-1] == -1){
                return -1;
            }
            int index = top[m-1];

            top[m-1] = next[index];

            next[index] = freespot;

            freespot = index;

            return arr[index];
        }
};

int main()
{
    return 0;
}