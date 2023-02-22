#include<bits/stdc++.h>
using namespace std;

class Stack{
    private:
        int *arr;
        int *top;
        int *next;
        int freespot;
        int n, s;

    public:
        Stack(int N, int S){
            n = N;
            s= S;
            arr = new int[s];
            top = new int[n];
            freespot = 0;
            next = new int[s];

            for(int i=0; i<n; i++){
                top[i] = -1;
            }

            for(int i=0; i<s; i++){
                next[i] = i+1;
            }
            next[s-1] = -1;
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
     
}