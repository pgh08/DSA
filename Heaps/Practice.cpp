#include<iostream>
#include<queue>
using namespace std;

int KthSmallest(int *arr, int n, int k){
    priority_queue<int> pq;

    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }

    for(int i=k; i<n; i++){
        if(pq.top() > arr[i]){
            pq.pop();

            pq.push(arr[i]);
        }
    }

    return pq.top();
}

int main()
{
    int arr[6] = {7,7,20,10,3,15};

    int k;
    cout<<"Enter the value of k"<<endl;
    cin>>k;

    int ans = KthSmallest(arr, 6, k);

    cout<<"Kth Samllest elemet is : "<<ans<<endl; 

    return 0;
}