#include<iostream>
using namespace std;

pair<bool,int> binarySearch(int num[], int s, int e, int key){
    //Base case.
    if(s > e){
        pair<bool,int> p = make_pair(false, -1);
        return p;
    }
    int mid = s + (e-s)/2;
    if(num[mid] == key){
        return {true, mid+1};
    }
    if(num[mid] > key){
        return binarySearch(num, s, mid-1, key);
    }
    else{
        return binarySearch(num, mid+1, e, key);
    }
}

int main()
{   
    int n = 6;
    int num[6] = {2,4,6,10,14,16};
    int s = 0;
    int e = n-1;
    int key;
    cout<<"Enter the key to search for : "<<endl;
    cin>>key;

    if(binarySearch(num, s, e, key).first){
        cout<<"Element found at position : "<<binarySearch(num, s, e, key).second<<endl;
    }
    else{
        cout<<"Element Not found"<<endl;
    }

    return 0;
}